/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:21 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:36:19 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	idx_stack(t_stack **stack, int *arr, int stack_size)
{
	t_stack	*curr;
	int		i;

	curr = *stack;
	while (curr)
	{
		i = 0;
		while (i < stack_size)
		{
			if (curr->content == arr[i])
			{
				curr->index = i;
				break ;
			}
			i++;
		}
		curr = curr->next;
	}
}

void	sort_arr(int *arr, int stack_size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < stack_size - 1)
	{
		j = 0;
		while (j < stack_size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	stack_to_array(t_stack **stack, int stack_size)
{
	int		i;
	int		*arr;
	t_stack	*curr;

	i = 0;
	arr = malloc(stack_size * sizeof(int));
	curr = *stack;
	while (curr)
	{
		arr[i] = curr->content;
		i++;
		curr = curr->next;
	}
	sort_arr(arr, stack_size);
	idx_stack(stack, arr, stack_size);
	free(arr);
}
