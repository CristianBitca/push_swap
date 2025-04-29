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

#include "pushswap.h"

void	free_stack(t_node *node_lst)
{
	t_node	*cur;

	while (node_lst)
	{
		cur = node_lst;
		node_lst = node_lst->next;
		free(cur);
	}
}

void	free_stack_list(t_stack_list *stack_list)
{
	if (stack_list)
	{
		free_stack(stack_list->a->first);
		free_stack(stack_list->b->first);
		free(stack_list->b);
		free(stack_list->a);
	}
	free(stack_list);
}

void	print_error(t_stack_list *stack_list, char *message)
{
	printf("Error\n");
	if (message)
		printf("%s", message);
	free_stack_list(stack_list);
	exit(EXIT_FAILURE);
}
