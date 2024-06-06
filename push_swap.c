#include "utils.h"

void ft_error(void)
{
    write(2, "Error\n", 6);
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
                // printf("check numbers error");
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

void check_len(char *str)
{
    int i = 0;
    while (str[i] == '-' || str[i] == '+' || str[i] == '0')
        i++;
    str += i;
    if (ft_strlen(str) > 10)
        ft_error();
}
void check_range(char *str)
{
    check_len(str);
    long number = ft_atoi(str);
    if(number > INT_MAX || number < INT_MIN)
        ft_error();
}

void treat(t_stack **stack_a, char *str)
{
    char **result;
    int i = 0;
    result = ft_split(str, ' ');
    while (result[i])
    {
        t_stack *new = NULL;
        check(result[i]);
        check_numbers(result[i]);
        check_range(result[i]);
        new = ft_lstnew(ft_atoi(result[i]), 0);
        ft_lstadd_back(stack_a, new);
        check_is_duplicated(*stack_a, ft_atoi(result[i]));
        free(result[i]);
        i++;
    }
    
    free(result);
}

int main(int ac, char **av)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (ac == 1)
        return 0;
    if(!av[1][0])
    {
        return 0;
    }
    int i = 1;
    while (av[i])
    {
        just_spaces(av[i]);
        treat(&stack_a, av[i]);
        i++;
    }
    int stacksize = stack_size(stack_a);
    // printf("stack size -> %d\n", stacksize);
    if((is_sorted(&stack_a) == 1) && stacksize == 2)
        sort_two(&stack_a);
    else if((is_sorted(&stack_a) == 1) && stacksize == 3)
        sort_three(&stack_a);
    else if((is_sorted(&stack_a) == 1) && stacksize <= 5)
        sort_five(&stack_a, &stack_b, stacksize);
    else
    {
        indexed(&stack_a, stacksize);
        radix(&stack_a, &stack_b, stacksize);
    }

    // t_stack *curr = stack_a;
    // while (curr)
    // {
    //     printf("value %ld | index %d\n", curr->content, curr->index);
    //     curr = curr->next;
    // }

    // system("leaks -q push_swap");
    return 0;
}