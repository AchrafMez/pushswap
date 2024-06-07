/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:39:58 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:46:48 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int input, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = input;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_stack **lst, t_stack *neww)
{
	if (lst == NULL || neww == NULL)
		return ;
	neww->next = *lst;
	*lst = neww;
}

void	ft_lstadd_back(t_stack **lst, t_stack *neww)
{
	t_stack	*curr;

	curr = *lst;
	if (*lst == NULL)
	{
		*lst = neww;
		return ;
	}
	else
	{
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = neww;
		curr->next->next = NULL;
	}
}

int	stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
