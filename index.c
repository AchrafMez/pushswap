/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:21 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/06 18:40:22 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void idx_stack(t_stack **stack, int *arr, int stack_size)
{
    t_stack *curr = *stack;

    while(curr)
    {
        int i = 0;
        while(i < stack_size)
        {
            if (curr->content == arr[i])
            {
                curr->index = i;
                break;
            }
            i++;
        }
        curr = curr->next;
    }
}

void sort_arr(int *arr, int stack_size)
{
    int i = 0;
    int j = 0;
    int tmp = 0;
    while(i < stack_size - 1)
    {
        j = 0;
        while(j < stack_size - i - 1)
        {
            if(arr[j] > arr[j + 1])
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

void stack_to_array(t_stack **stack, int stack_size)
{
    t_stack *curr;
    int *arr;

    arr = malloc(stack_size * sizeof(int));
    curr = *stack;
    int i = 0;
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