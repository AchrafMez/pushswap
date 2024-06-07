/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:53:01 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:37:34 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// is sorted
int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cmp;

	tmp = *stack;
	cmp = tmp;
	if (!stack)
		return (0);
	while (tmp->next)
	{
		if (cmp->content > tmp->next->content)
			return (1);
		else
		{
			cmp = tmp->next;
			tmp = tmp->next;
		}
	}
	return (0);
}

int	digit_len(int max_num)
{
	int	len;

	len = 0;
	while (max_num != 0)
	{
		max_num /= 10;
		len++;
	}
	return (len);
}

int	count_bits(int number)
{
	int	count;

	count = 0;
	while (number)
	{
		number = number >> 1;
		count++;
	}
	return (count);
}

void	radix(t_stack **stack_a, t_stack **stack_b, int max)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	max_bits = count_bits(max);
	while (i < max_bits)
	{
		j = 0;
		size = stack_size(*stack_a);
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while ((*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
