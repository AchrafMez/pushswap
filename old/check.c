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