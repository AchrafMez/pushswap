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
int check_numbers(char *str)
{
    while(*str)
    {
        if(*str >= '0' && *str <= '9')
            return 0;
        else if(!(*str == ' ' || *str == '-' || *str == '+'))
            {
                printf("check numbers error");
                return 1;
            }
            str++;
    }
    return -1;

}

void just_spaces(char *str)
{
    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if(*str == '\0')
        ft_error();
}
void check_range(char *str)
{
    long number = ft_atoi(str);
    if(number > INT_MAX || number < INT_MIN)
        ft_error();
}

// void addto(t_stack *stack_a, t_stack **new, char *str)
// {
    // new = ft_lstnew(ft_atoi(str));
    // ft_lstadd_back(stack_a, new);

 
// }

void treat(t_stack **stack_a, char *str)
{
    char **result;
    int i = 0;
    result = ft_split(str, ' ');
    t_stack *new;
    while (result[i])
    {
        new = NULL;
        check(result[i]);
        check_numbers(result[i]);
        check_range(result[i]);
        new = ft_lstnew(ft_atoi(result[i]));
        ft_lstadd_back(stack_a, new);
        check_is_duplicated(*stack_a, ft_atoi(result[i]));
        free(result[i]);
        i++;
    }
    free(result);
}

int main(int ac, char **av)
{
    if (ac == 1)
        return 0;
    if(!av[1][0])
    {
        return 0;
    }
    int i = 1;
    t_stack *stack_a;
    while (av[i])
    {
        just_spaces(av[i]);
        treat(&stack_a, av[i]);
        i++;
    }
    int size = stack_size(stack_a);

    printf("size == %d\n", size);
    while(stack_a)
    {
        printf("stack value -> %ld\n", stack_a->content);
        stack_a = stack_a->next;
    }
    return 0;
}


//after splitting the aguemtn I checked their range and if there is an error.
//now i have to check if there is an argument duplicated or not

//checking leaks
//make the instructions
