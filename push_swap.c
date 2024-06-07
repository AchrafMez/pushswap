/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:08 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:35:43 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	treat(t_stack **stack_a, char *str)
{
	char	**result;
	int		i;
	t_stack	*new;

	i = 0;
	result = ft_split(str, ' ');
	while (result[i])
	{
		new = NULL;
		check(result[i]);
		check_numbers(result[i]);
		check_range(result[i]);
		new = ft_lstnew(ft_atoi(result[i]), 0);
		ft_lstadd_back(stack_a, new);
		check_is_duplicated(*stack_a, ft_atoi(result[i]));
		free(result[i]);
		i++;
	}
	free(result);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int stacksize)
{
	if ((is_sorted(stack_a) == 1) && stacksize == 2)
		sort_two(stack_a);
	else if ((is_sorted(stack_a) == 1) && stacksize == 3)
		sort_three(stack_a);
	else if ((is_sorted(stack_a) == 1) && stacksize <= 5)
		sort_five(stack_a, stack_b, stacksize);
	else if (is_sorted(stack_a) == 1)
	{
		stack_to_array(stack_a, stacksize);
		radix(stack_a, stack_b, stacksize);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		stacksize;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (args_check(ac, av) == 0)
		return (0);
	while (av[i])
	{
		just_spaces(av[i]);
		treat(&stack_a, av[i]);
		i++;
	}
	stacksize = stack_size(stack_a);
	sort_stack(&stack_a, &stack_b, stacksize);
	return (0);
}
