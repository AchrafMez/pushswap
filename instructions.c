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
    printf("sa\n");
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
    printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
    if(!stack_a || !stack_b || !(*stack_a)->next || !(*stack_b)->next)
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

    t_stack *tmp = *a;
    t_stack *new = ft_lstnew(tmp->content);

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
    printf("rra\n");
}
// void rra(t_stack **a)
// {
//     t_stack *curr;
//     t_stack *prev = NULL;

//     curr = *a;
//     while (curr->next)
//     {
//         prev = curr;
//         curr = curr->next;
//     }
//     if (prev)
//     {
//         prev->next = NULL;
//         ft_lstadd_front(a, curr);
//     }
//     printf("rra");
// }


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