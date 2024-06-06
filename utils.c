/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:39:54 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/06 18:39:55 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
long ft_atoi(char *str)
{
    long number = 0;
    int sing = 0;
    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if(*str == '-' || *str == '+')
    {
		if(*(str+1) == '\0')
			ft_error();
        else if(*str == '-')
            sing = 1;
        str++;
    }
    while((*str >= '0' && *str <= '9') || *str+1 == ' ')
    {
		if(*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
        number = number * 10 + *str - '0';
        str++;
    }
    if(sing == 1)
        return number *= -1;
    return number;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

int check_is_valid(char **sres)
{
	int i = 0;
	int aret = 0;
	while(sres[i])
	{
		aret = ft_atoi(sres[i]);
		i++;
	}
	return 0;
}