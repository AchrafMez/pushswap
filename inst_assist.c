/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:24:16 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:36:23 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*new;

	if (!(*a) || !((*a)->next))
		return ;
	new = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, new);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!(b) || !((*b)->next))
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, tmp);
	write(1, "rb\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*new;

	tmp = *a;
	new = NULL;
	if (!(a) || !((*a)->next))
		return ;
	new = tmp->next;
	while (tmp->next->next)
	{
		tmp = tmp->next;
		new = tmp->next;
	}
	tmp->next = NULL;
	ft_lstadd_front(a, new);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*new;

	if (!(b) || !((*b)->next))
		return ;
	tmp = *b;
	new = NULL;
	new = tmp->next;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
		new = tmp->next;
	}
	tmp->next = NULL;
	ft_lstadd_front(b, new);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (!(a) || !((*a)->next) || !(b) || !((*b)->next))
		return ;
	else
		rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
