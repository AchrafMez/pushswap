#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "pushswap.h"
#include "libft/libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*new;
// 	int		len;    
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	if (!s1 || !s2)
// 		return (NULL);
// 	len = strlen(s1) + ft_strlen(s2);
// 	new = malloc(len + 1);
// 	if (!new)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		new[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		new[i + j] = s2[j];
// 		j++;
// 	}
// 	new[i + j] = '\0';
// 	return (new);
// }
    // if(ac > 1)
    // {
    // static char *get;
        // int last = ac - 1;
        // int i = 1;
        // char *result;
        // // char *space = " ";
        // int len = 0;
        // while (i <= last)
        // {
        // // int i = 1;
        // len = strlen(av[i]);
        // result = ft_strjoin(av[i], av[i+1]);
        // // result = ft_split(av[i], ' ');
        // // printf("%s\n", av[i]);
        // // printf("last == %d\n", last);
        // // printf("ac == %d\n", ac);
        // i++;
        // get = result;
        // }
    // 

int main(int ac, char **av)
{
    if(ac == 2)
    {
        av = ft_split(av[1], ' ');
    }
    int i = 1;
    while (1)
    {

    printf("%s", av[i]);
    i++;
    if(!av[i])
        break;
    }
    // printf("%s", av[1]);
    // printf("%s", av[2]);
    // printf("%s", av[3]);
    // printf("%s", av[4]);
    // printf("%s", av[5]);
    // printf("%s", av[6]);
    // printf("%s", av[7]);
    // printf("%s", av[8]);
    // printf("%s", av[9]);
    // printf("%s", av[10]);
    // printf("%s", av[11]);
    // printf("%s", av[12]);
    // printf("%s", av[13]);
    // printf("%s", av[14]);
    // printf("%s", av[15]);
}
