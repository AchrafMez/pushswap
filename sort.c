#include "utils.h"

int is_sorted(t_stack **stack)
{
    t_stack *tmp = *stack;
    t_stack *cmp;
    cmp = tmp;

    if(!stack)
        return 0;
    while(tmp->next)
    {
        if(cmp->content > tmp->next->content)
        {
            printf("the stack is not sorted\n");
            return 1;
        }
        else{
            cmp = tmp->next;
            tmp = tmp->next;
        }
    }
    printf("the stack is sorted\n");
    return 0;
}
void sort_two(t_stack **stack)
{
    t_stack *tmp = *stack;
    if((tmp)->content > (tmp)->next->content)
        sa(&*stack);
}

void sort_three(t_stack **stack)
{
    t_stack *tmp = *stack;
    if(tmp->content > tmp->next->content && tmp->next->content < tmp->next->next->content &&
        !(tmp->next->next->content < tmp->content))
        sa(&*stack);
    else if(tmp->content > tmp->next->content && tmp->next->content > tmp->next->next->content)
    {
        sa(&*stack);
        rra(&*stack);
    }
    else if(tmp->content > tmp->next->content && tmp->content > tmp->next->next->content &&
        tmp->next->content < tmp->next->next->content)
        ra(&*stack);
    else if(tmp->next->content > tmp->content && tmp->next->content > tmp->next->next->content &&
        tmp->content < tmp->next->next->content)
    {
        sa(&*stack);
        ra(&*stack);
    }
    else if(tmp->content < tmp->next->content && tmp->content > tmp->next->next->content &&
        tmp->next->content > tmp->content && tmp->next->content > tmp->next->next->content)
        rra(&*stack);
}

void sort_five(t_stack **stack_a, t_stack **b)
{
    t_stack *tmp = *stack_a;
    long low = tmp->content;
    // t_stack *new = tmp;
    while(tmp->next)
    {
        if(low > tmp->content)
            low = tmp->content;
        tmp = tmp->next;
    }
        printf("low value -> %ld\n", low);

    pb(&tmp, b);
        printf(".......................................");
        printf("stack b value -> %ld\n", (*b)->content);

        // printf("stack b value -> %ld\n", (*stack_b)->next->content);

    // printf("low value after %ld\n", low);
}