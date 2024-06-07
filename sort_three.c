/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:38:20 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:37:02 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_one(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->content > tmp->next->content
		&& tmp->next->content < tmp->next->next->content
		&& !(tmp->next->next->content < tmp->content))
		sa(&*stack);
}

void	case_two(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->content < tmp->next->content
		&& tmp->content > tmp->next->next->content
		&& tmp->next->content > tmp->content
		&& tmp->next->content > tmp->next->next->content)
		rra(&*stack);
}

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	case_one(stack);
	if (tmp->content > tmp->next->content
		&& tmp->next->content > tmp->next->next->content)
	{
		sa(&*stack);
		rra(&*stack);
	}
	else if (tmp->content > tmp->next->content
		&& tmp->content > tmp->next->next->content
		&& tmp->next->content < tmp->next->next->content)
		ra(&*stack);
	else if (tmp->next->content > tmp->content
		&& tmp->next->content > tmp->next->next->content
		&& tmp->content < tmp->next->next->content)
	{
		sa(&*stack);
		ra(&*stack);
	}
	case_two(stack);
}
