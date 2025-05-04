/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:27:25 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/29 21:24:47 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack_list	*stack_list;

	stack_list = 0;
	if (argc < 2)
	{
		print_error(stack_list, ARG_NUMBER);
		return (0);
	}
	else
	{
		init_stack_list(stack_list, &argv[1]);
		free_stack_list(stack_list);
	}
}
