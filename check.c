/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:40:25 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:36:00 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_is_duplicated(t_stack *stack, long number)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		return ;
	while (temp->next)
	{
		if (temp->content == number)
			ft_error();
		temp = temp->next;
	}
}

void	check(char *str)
{
	int	sign;
	int	signp;

	sign = 0;
	signp = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign++;
		else if (*str == '+')
			signp++;
		if (sign > 1 || signp > 1 || (sign == 1 && signp == 1))
			ft_error();
		str++;
	}
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			ft_error();
		str++;
	}
}

int	check_numbers(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (0);
		else if (!(*str == ' ' || *str == '-' || *str == '+'))
			return (1);
		str++;
	}
	return (-1);
}

void	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '-' || str[i] == '+' || str[i] == '0')
		i++;
	str += i;
	if (ft_strlen(str) > 10)
		ft_error();
}

void	check_range(char *str)
{
	long	number;

	check_len(str);
	number = ft_atoi(str);
	if (number > INT_MAX || number < INT_MIN)
		ft_error();
}
