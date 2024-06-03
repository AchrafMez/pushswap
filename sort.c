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
            new_node = tmp;
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
    // while (min != lst)
    // min->index > 2 rra min->index <= 2 ra

void sort_five_helper(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *new_node = get_low(stack_a);
    while((*stack_a)->content != new_node->content)
    {
        if(new_node->index <= 2)
            ra(stack_a);
        else if(new_node->index > 2)
            rra(stack_a);
        update_indices(stack_a);
    }
    pb(stack_a, stack_b);
    t_stack *tmp = *stack_a;
    while(tmp){
            printf("stack a content ->%ld \n", (tmp)->content);
            (tmp) = (tmp)->next;
        }
}

void sort_five(t_stack **stack_a, t_stack **b, int size)
{
        if(size == 4)
        {
            sort_five_helper(stack_a, b);
            sort_three(stack_a);
            pa(stack_a, b);
        }
        else if(size == 5)
        {
            sort_five_helper(stack_a, b);
            sort_five_helper(stack_a, b);
            sort_three(stack_a);
            pa(stack_a, b);
            pa(stack_a, b);
        }
}

// now everyting is good
// i just have emplement the radix sort algorithm.
//get max

t_stack *get_max(t_stack **a)
{
    t_stack *tmp = *a;
    t_stack *new_node = tmp;

    while(tmp)
    {
        if(new_node->content < tmp->content)
            new_node = tmp;
        else
            tmp = tmp->next;
    }
    return new_node;
}
int digit_len(int max_num)
{
    int len = 0;
    while(max_num != 0)
    {
        max_num /= 10;
        len++;
    }
    return len;
}

void radix(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp = *stack_a;

    while(tmp)
    {
        if((tmp->content % 10) < 5)
            pb();
    }
}