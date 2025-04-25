/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:27:25 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/25 13:27:26 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void    print_error(char *message)
{
    printf("Error\n");
    printf("%s", message);
    exit(EXIT_SUCCESS);
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
    b = a;
    // init_stack(&b, argc, 0);
}
