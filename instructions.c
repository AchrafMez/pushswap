/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:17 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:36:32 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*curr;
	long	tmp;

	curr = *stack_a;
	if (!curr)
		return ;
	else
	{
		tmp = curr->content;
		curr->content = curr->next->content;
		curr->next->content = tmp;
	}
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	t_stack	*curr;
	long	tmp;

	curr = *stack_b;
	if (!curr)
		return ;
	else
	{
		tmp = curr->content;
		curr->content = curr->next->content;
		curr->next->content = tmp;
	}
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!(*b))
		return ;
	new = ft_lstnew((*b)->content, (*b)->index);
	tmp = *b;
	ft_lstadd_front(a, new);
	*b = (*b)->next;
	free(tmp);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*new;

	if (!(*a))
		return ;
	tmp = *a;
	new = ft_lstnew(tmp->content, tmp->index);
	ft_lstadd_front(b, new);
	*a = (*a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}
