/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:25 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/06 18:40:26 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void check_is_duplicated(t_stack *stack, long number)
{
    t_stack *temp = stack;
    if(!stack)
        return ;
    while(temp->next)
    {
        if(temp->content == number)
            ft_error();
        temp = temp->next;
    }   
}