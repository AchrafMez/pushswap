/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:39:34 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:47:50 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	long			content;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				sort_stack(t_stack **stack_a, t_stack **stack_b,
						int stacksize);
long				ft_atoi(char *str);
void				ft_error(void);
int					args_check(int ac, char **av);
void				just_spaces(char *str);

// libc_utils
char				**ft_split(char const *s, char c);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strlen(const char *s);

// stack_utils
t_stack				*ft_lstnew(int content, int index);
void				ft_lstadd_back(t_stack **lst, t_stack *neww);
int					stack_size(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *neww);

// check
void				check_is_duplicated(t_stack *stack, long number);
void				check(char *str);
int					check_numbers(char *str);
void				check_len(char *str);
void				check_range(char *str);
int					check_is_valid(char **sres);

// instructions
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

// sort
void				sort_two(t_stack **stack);
void				sort_three(t_stack **stack);
t_stack				*get_low(t_stack **a);
void				sort_five_helper(t_stack **stack_a, t_stack **stack_b);
void				sort_five(t_stack **stack_a, t_stack **b, int size);

// radix
int					is_sorted(t_stack **stack);
int					digit_len(int max_num);
int					get_max(t_stack *a);
int					count_bits(int number);
void				radix(t_stack **stack_a, t_stack **stack_b, int stacksize);

// index
void				idx_stack(t_stack **stack, int *arr, int stack_size);
void				sort_arr(int *arr, int stack_size);
void				stack_to_array(t_stack **stack, int stack_size);

#endif