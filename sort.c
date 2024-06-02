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

t_stack *get_low(t_stack **a)
{
    t_stack *tmp = *a;
    t_stack *new_node;
    new_node = tmp;
    while(tmp)
    {
        if(new_node->content > tmp->content)
            new_node->content = tmp->content;
        tmp = tmp->next;
    }
    return new_node;
}

void update_indices(t_stack **stack)
{
    t_stack *tmp = *stack;
    int idx = 0;
    while(tmp)
    {
        tmp->index = idx;
        tmp = tmp->next;
        idx++;
    }
}
void sort_five(t_stack **stack_a, t_stack **b)
{
    t_stack *tmp = *stack_a;
    t_stack *tmp2 = *stack_a;
    // (void)b;
    // t_stack *new = tmp;
    // while(tmp)
    // {
    //     printf(" content before low ---> %ld\n", tmp->content);
    //      tmp = tmp->next;
    // }
    t_stack *new_node = get_low(stack_a);
    while((*stack_a)->content != new_node->content)
    {
        if(new_node->index >= 2)
            ra(stack_a);
        else if(new_node->index < 2)
            rra(stack_a);
    }
        printf("new node value -> %ld\n", new_node->content);
    // while (min != lst)
    // min->index > 2 rra min->index <= 2 ra
    // pb(&tmp, b);
    //     printf(".......................................");
    //     printf("stack b value -> %ld\n", (*b)->content);

        // printf("stack b value -> %ld\n", (*stack_b)->next->content);

    // printf("low value after %ld\n", low);
}