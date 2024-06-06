#include "utils.h"

t_stack *ft_lstnew(int input, int index)
{
    t_stack *node;
    node = (t_stack *)malloc(sizeof(t_stack));
    if(!node)
        return NULL;
    node->content = input;
    node->index = index;
    node->next = NULL;
    return node;
}

t_stack *ft_lstlast(t_stack *lst)
{
    if(!lst)
        return NULL;
    while(lst)
        lst = lst->next; 
    return lst;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void ft_lstadd_back(t_stack **lst, t_stack *new)
{
    t_stack *curr;
    
    curr = *lst;
    if(*lst == NULL)
    {
        *lst = new;
        return ;
    }
    else{

    while (curr->next != NULL)
        curr = curr->next;
    curr->next = new;
    curr->next->next = NULL;
    }
}

int stack_size(t_stack *lst)
{
    int i = 0;
    if(!lst)
        return 0;
    while(lst)
    {
        lst = lst->next;
        i++;
    }
    return i;
}