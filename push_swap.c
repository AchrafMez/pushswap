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

char *treat(char *str)
{
    char **result;
    int i = 0;
    t_stack *new;
    int number = 0;
    // t_stack *stack_a = NULL;
    result = ft_split(str, ' ');
    while (result[i])
    {
        new = NULL;
        check(result[i]);
        number = ft_atoi(result[i]);
        free(result[i]);
        //i need to creat stacks and lis on them the number by lstaddback
        //i need some work here
        // ft_lstadd_back(void);
        i++;
    }
    // int size = 0;
    // t_stack *curr = stack_a;
    // while (curr->next != NULL)
    // {
    //     size++;
    //     printf("content -> %d\n", curr->content);
    //     printf("size -> %d\n", size);
    //     curr = curr->next;
    // }
    free(result);
    return result;
}

int main(int ac, char **av)
{
    // int end = ac - 1;
    // t_stack **stack_test = NULL;
    if (ac == 1)
        return 0;
    if(!av[1][0])
    {
        printf("Error\n");
        return 0;
    }
    int i = 1;
    // int j = 0;
    while (av[i])
        treat(av[i++]);
    t_stack *stack_a = NULL;
    t_stack *new;
    i = 1;
    while(av[i])
    {
        new = ft_lstnew(ft_atoi(av[i]));
        ft_lstadd_back(&stack_a, new);
        i++;
    }

    int size = stack_size(stack_a);
    printf("size == %d\n", size);
    
    return 0;
}