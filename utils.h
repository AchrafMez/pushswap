#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "libft/libft.h"
#include "ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdbool.h>
# include <limits.h>

typedef struct s_list
{
    int             content;
    struct s_list   *next;
} t_list;

typedef struct s_stack
{
    int content;
    struct s_stack *next;
} t_stack;

int ft_atoi(char *str);
void ft_error(void);
//lib_utils
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_strlen(const char *s);
//stack_utils
t_list *ft_lstnew(int content);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
#endif