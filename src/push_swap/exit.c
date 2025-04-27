/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:28:13 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/26 19:28:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	free_nodes(t_node *node, int size)
{
	int	i;

	i = 0;
	size = 0;
	node = 0;
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free_nodes(stack->first, stack->size);
		free(stack->first);
		free(stack->last);
	}
	free(stack);
}

void	free_stack_list(t_stack_list *stack_list)
{
	// if (stack_list->a)
	// {
	// 	// free_stack(stack_list->a);
	// 	free(stack_list->a);
	// }
	// if (stack_list->b)
	// {
	// 	// free_stack(stack_list->b);
	// 	free(stack_list->b);
	// }
	free(stack_list);
}

void    print_error(t_stack_list *stack_list, char *message)
{
	printf("Error\n");
	printf("%s", message);
	free_stack_list(stack_list);
	exit(EXIT_FAILURE);
}
