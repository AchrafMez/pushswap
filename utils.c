/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezioun <amezioun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:55:05 by amezioun          #+#    #+#             */
/*   Updated: 2024/04/27 18:55:54 by amezioun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
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

static int	count(char const *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			wcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wcount);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static void	ft_free(char **new, int j)
{
	while (j >= 0)
	{
		free(new[j]);
		j--;
	}
	free(new);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!new)
		return (NULL);
	while (s && s[i] != '\0' && j < count(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		new[j] = ft_substr(s, i, word_len(s, c, i));
		if (!new[j])
		{
			ft_free(new, j);
			return (NULL);
		}
		i += word_len(s, c, i);
		j++;
	}
	new[j] = NULL;
	return (new);
}