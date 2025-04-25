#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/libft/include/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define ARG_NUMBER "You entered a wrong amount of arguments."

typedef struct s_stack
{
    int n;
    struct s_stack *next;

} t_stack;

void    init_stack(t_stack *stack, int n, char **values);

#endif