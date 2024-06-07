/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:03 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:37:06 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort two
void	sort_two(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if ((tmp)->content > (tmp)->next->content)
		sa(&*stack);
}

// get low
t_stack	*get_low(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*new_node;

	tmp = *a;
	new_node = tmp;
	while (tmp)
	{
		if (new_node->content > tmp->content)
			new_node = tmp;
		tmp = tmp->next;
	}
	return (new_node);
}

void	sort_five_helper(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*new_node;

	new_node = get_low(stack_a);
	while ((*stack_a)->content != new_node->content)
	{
		if (new_node->index <= 2)
			ra(stack_a);
		else if (new_node->index > 2)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **b, int size)
{
	if (size == 4)
	{
		sort_five_helper(stack_a, b);
		sort_three(stack_a);
		pa(stack_a, b);
	}
	else if (size == 5)
	{
		sort_five_helper(stack_a, b);
		sort_five_helper(stack_a, b);
		sort_three(stack_a);
		pa(stack_a, b);
		pa(stack_a, b);
	}
}
