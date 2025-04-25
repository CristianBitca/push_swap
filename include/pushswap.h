#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../lib/libft/include/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define S_MAX_INT "2147483647"
# define S_MIN_INT "-2147483648"
# define ARG_NUMBER "You entered a wrong amount of arguments.\n"
# define INT_ERROR "One value of array is not integer.\n"
# define INT_OVERFLOW "One value of array is out of the limits of integer datatype.\n"

typedef struct s_stack
{
    int n;
    struct s_stack *next;

} t_stack;

void    print_error(char *message);

void    init_stack(t_stack *stack, int n, char **values);
long int	ps_atoi(const char *nptr);

#endif