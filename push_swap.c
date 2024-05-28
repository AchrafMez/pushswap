#include "utils.h"

void ft_error(void)
{
    write(1, "error\n", 6);
    exit(1);
}
void check(char *str)
{
    int sign = 0;
    int signp = 0;
    while(*str == '-' || *str == '+')
    {
        if(*str == '-')
            sign++;
        else if(*str == '+')
            signp++;
        if(sign > 1 || signp > 1 || (sign == 1 && signp == 1))
            ft_error();
        str++;
    }
    while(*str)
    {
        if(!(*str >= '0' && *str <= '9'))
            ft_error();
        str++;
    }
}

void treat(char *str)
{
    char **result;
    int i = 0;
    t_list *new;
    // int number = 0;
    result = ft_split(str, ' ');
    while (result[i])
    {
        check(result[i]);
        new = ft_lstnew(ft_atoi(result[i]));
        printf("number in list ==%d\n", new->content);
        free(result[i]);
        //i need to creat stacks and lis on them the number by lstaddback
        //i need some work here
        // ft_lstadd_back(void);
        i++;
    }
    free(result);
}

int main(int ac, char **av)
{
    // int end = ac - 1;
    if (ac == 1)
        return 0;
    if(!av[1][0])
    {
        printf("Error\n");
        return 0;
    }
    int i = 1;
    while (av[i])
    {
        treat(av[i++]);
    }
    return 0;
}