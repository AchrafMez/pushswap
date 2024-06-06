/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:17 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/06 18:43:29 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void sa(t_stack **stack_a)
{    
    t_stack *curr;
    long tmp;
    
    curr = *stack_a;
    if(!curr)
        return ;
    else
    {
        tmp = curr->content;
        curr->content = curr->next->content;
        curr->next->content = tmp;
    }
    write(2, "sa\n", 3);
}

void sb(t_stack **stack_b)
{
    t_stack *curr;
    long tmp;
    
    curr = *stack_b;
    if(!curr)
        return ;
    else
    {
        tmp = curr->content;
        curr->content = curr->next->content;
        curr->next->content = tmp;
    }
    write(2, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    if(!stack_a || !stack_b || !(*stack_a)->next || !(*stack_b)->next)
        return ;
    sa(stack_a);
    sb(stack_b);
    write(2, "ss\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
    if(!(*b))
        return ;
    t_stack *new = ft_lstnew((*b)->content, (*b)->index);
    t_stack *tmp = *b;
    ft_lstadd_front(a, new);
    *b = (*b)->next;
    free(tmp);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    if (!(*a))
        return ;

    t_stack *tmp = *a;
    t_stack *new = ft_lstnew(tmp->content, tmp->index);

    ft_lstadd_front(b, new);
    *a = (*a)->next;
    free(tmp);
    write(1, "pb\n", 3);
}

void ra(t_stack **a)
{
    if(!(*a) || !((*a)->next))
        return ;
    t_stack *new = *a;

    *a = (*a)->next;
    ft_lstadd_back(a, new);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    if(!(b) || !((*b)->next))
        return ;
    t_stack *tmp = *b;
    *b = (*b)->next;
    ft_lstadd_back(b, tmp);
    write(1, "rb\n", 3);
}

void rra(t_stack **a)
{
    t_stack *tmp = *a;
    t_stack *new = NULL;

    if(!(a) || !((*a)->next))
        return ;
    new = tmp->next;
    while(tmp->next->next)
    {
        tmp = tmp->next;
        new = tmp->next;
    }
    tmp->next = NULL;
    ft_lstadd_front(a, new);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    if(!(b) || !((*b)->next))
        return ;
    t_stack *tmp = *b;
    t_stack *new = NULL;

    new = tmp->next;
    while(tmp->next->next != NULL)
    {
        tmp = tmp->next;
        new = tmp->next;
    }
    tmp->next = NULL;
    ft_lstadd_front(b, new);
    write(1, "rrb\n", 4);
}

void rrr(t_stack **a, t_stack **b)
{
    if(!(a) || !((*a)->next) || !(b) || !((*b)->next))
        return ;
    else
        rra(a);
        rrb(b);
    write(1, "rrr\n", 4);
}
