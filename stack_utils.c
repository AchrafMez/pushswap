#include "utils.h"

t_list *ft_lstnew(int input)
{
    t_list *node;
    node = malloc(sizeof(t_list));
    if(!node)
        return NULL;
    node->content = input;
    node->next = NULL;
    return node;
}

t_list *ft_lstlast(t_list *lst)
{
    if(!lst)
        return NULL;
    while(lst)
        lst = lst->next; 
    return lst;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *curr;
    curr = *lst;
    if(!lst)
        return ;
    if(!*lst)
    {
        *lst = new;
        return ;
    }
        curr = ft_lstlast(*lst);
        curr->next = new;
}