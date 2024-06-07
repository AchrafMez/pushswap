/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:39:54 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:37:14 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	args_check(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		return (0);
	else if (!av[1][0])
		return (0);
	else
		return (1);
}

void	just_spaces(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '\0')
		ft_error();
}

int	check_is_valid(char **sres)
{
	int	i;
	int	aret;

	i = 0;
	aret = 0;
	while (sres[i])
	{
		aret = ft_atoi(sres[i]);
		i++;
	}
	return (0);
}

long	ft_atoi(char *str)
{
	long	number;
	int		sing;

	number = 0;
	sing = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*(str + 1) == '\0')
			ft_error();
		else if (*str == '-')
			sing = 1;
		str++;
	}
	while ((*str >= '0' && *str <= '9') || *str + 1 == ' ')
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		number = number * 10 + *str - '0';
		str++;
	}
	if (sing == 1)
		return (number *= -1);
	return (number);
}
