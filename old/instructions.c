#include "utils.h"

void sa(t_stack *stack_a)
{
    int tmp;
    if(!stack_a || stack_a->next)
        return ;
    else
    {
        tmp = stack_a->content;
        stack_a->content = stack_a->next->content;
        stack_a->next->content = tmp;
    }
    printf("sa\n");
}

void sb(t_stack *stack_b)
{
    int tmp;
    if(!stack_b || stack_b->next)
        return ;
    else
    {
        tmp = stack_b ->content;
        stack_b->content = stack_b->next->content;
        stack_b->next->content = tmp;
    }
    printf("sa\n");
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    if(!stack_a || !stack_b || stack_a->next || !stack_b->next)
        return ;
    sa(stack_a);
    sb(stack_b);
    printf("ss\n");
}

void pa(t_stack **a, t_stack **b)
{
    if(!(*b))
        return ;
    t_stack *new = ft_lstnew((*b)->content);
    t_stack *tmp = *b;
    ft_lstadd_front(a, new);
    *b = (*b)->next;
    free(tmp);
    printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    if (!(*a))
        return ;

    t_stack *new = ft_lstnew((*a)->content);
    t_stack *tmp = *a;

    ft_lstadd_front(b, new);
    *a = (*a)->next;
    free(tmp);
    printf("pb\n");
}
void ra(t_stack **a)
{
    if(!(*a) || !((*a)->next))
        return ;
    t_stack *new = *a;

    *a = (*a)->next;
    ft_lstadd_back(a, new);
    printf("ra\n");
}

void rb(t_stack **b)
{
    if(!(b) || !((*b)->next))
        return ;
    t_stack *tmp = *b;
    *b = (*b)->next;
    ft_lstadd_back(b, tmp);
    printf("rb\n");
}

// void rra(t_stack **a)
// {
//     t_stack *tmp = *a;
//     t_stack *new = NULL;

//     if(!(a) || !((*a)->next))
//         return ;
//     new = tmp->next;
//     while(tmp->next->next)
//     {
//         tmp = tmp->next;
//         new = tmp->next;
//     }
//     tmp->next = NULL;
//     ft_lstadd_front(a, new);
// }

void rra(t_stack **a)
{
    t_stack *curr;
    t_stack *prev = NULL;

    curr = *a;
    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev)
    {
        prev->next = NULL;
        ft_lstadd_front(a, curr);
    }
    printf("rra");
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
    // new = ft_lstnew(new->content);
    ft_lstadd_front(b, new);
    printf("rrb\n");
}

void rrr(t_stack **a, t_stack **b)
{
    if(!(a) || !((*a)->next) || !(b) || !((*b)->next))
        return ;
    else
        rra(a);
        rrb(b);
    printf("rrr");
}