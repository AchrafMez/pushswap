#include "utils.h"
int ft_atoi(char *str)
{
    int number = 0;
    int sing = 0;
    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
            sing = 1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        number = number * 10 + *str - '0';
        str++;
    }
    if(*str)
    {
        write(1, "eror in args\n", 13);
        exit(1);    
    }
    if(sing == 1)
        return number *= -1;
    return number;
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