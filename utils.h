#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "libft/libft.h"
#include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdbool.h>
# include <limits.h>

// typedef struct s_list
// {
//     int             content;
//     struct s_list   *next;
// } t_list;

typedef struct s_stack
{
    long content;
    unsigned int index;
    struct s_stack *next;
} t_stack;

long ft_atoi(char *str);
void ft_error(void);

//lib_utils
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(const char *s);

//stack_utils
t_stack *ft_lstnew(int content);
t_stack *ft_lstlast(t_stack *lst);
void ft_lstadd_back(t_stack **lst, t_stack *new);
int stack_size(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

//check
void check_is_duplicated(t_stack *stack, long number);

//inst
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);

//sort
int is_sorted(t_stack **stack);
void sort_two(t_stack **stack);
void sort_three(t_stack **stack);
void sort_five(t_stack **stack_a, t_stack **b, int size);
void update_indices(t_stack **stack);
void sort_five_helper(t_stack **stack_a, t_stack **stack_b);

//radix
t_stack *get_max(t_stack *a);
int digit_len(int max_num);
void radix(t_stack **stack_a, t_stack **stack_b, int max);
int count_bits(int number);

int indexed(t_stack *stack, int stack_size);
void sort_arr(int *arr, int stack_size);
void idx_stack(t_stack *stack, int *arr, int stack_size);

#endif