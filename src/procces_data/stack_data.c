
#include "../../include/pushswap.h"

void    init_stack(t_stack *stack, int n, char **values)
{
    int i;

    i = 1;
    while (i < n)
    {
        if (!values)
            stack->n = 0;
        else
            stack->n = ft_atoi(values[i]);
        printf("%d ", stack->n);
        i++;
    }
    printf("\n");
    // while (stack)
    // {
    //     stack->n = ;
    //     stack = stack->next;
    // }
}