/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc_assist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 10:42:19 by amezioun          #+#    #+#             */
/*   Updated: 2024/06/07 13:36:37 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		strlen;
	char	*str;

	i = 0;
	strlen = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (*s == 0 || start > (unsigned int)(size - 1))
		return (ft_strdup(""));
	if (len <= (size - start))
		new = malloc(len + 1);
	else
		new = malloc((size - start) + 1);
	if (!new)
		return (NULL);
	while (s[i + start] && (i < len))
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
