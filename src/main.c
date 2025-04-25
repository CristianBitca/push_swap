
#include "../include/pushswap.h"

void    print_error(char *message)
{
    printf("Error\n");
    printf("%s\n", message);
}

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc < 2)
    {
        print_error(ARG_NUMBER);
        return (0);
    }
    init_stack(&a, argc, argv);
    init_stack(&b, argc, 0);
}