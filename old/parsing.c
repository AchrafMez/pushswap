#include "pushswap.h"

int ft_atoi(char *str)
{
    int number = 0;
    int sign = 0;

    while(*str == ' ' || (*str >= 9 && *str <= 19))
        str++;
    if(*str == '-' || *str == '+')
    {
        if(*str == '-')
            sign = 1;
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        number = number * 10 + *str - '0';
        str++;
    }
    if(*str)
    {
        write(1, "error", 5);
        exit(1);
    }
    if(sign == 1)
        return number * -1;
    return number;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int arg = ft_atoi(av[1]);
        printf("%d", arg);
    }
}