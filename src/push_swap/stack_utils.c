/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:32:49 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/26 21:33:04 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	append_stack(t_stack *stack, int num)
{
	t_node *node;
	t_node *new;

	new = ft_calloc(sizeof(t_node), 1);
	node = stack->first;
	node->n = num;
	node->prev = node;
	node->next = new;

}

t_node	*stack_last(t_stack *stack)
{
	t_node *node;

	node = stack->first;
	if (!node)
		return (0);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

// int	stack_size(t_node *node)
// {
// 	int	i;

// 	i = 0;
// 	if (!node)
// 		return (i);
// 	while (node->next)
// 	{
// 		i++;
// 		node = node->next;
// 	}
// 	return (i);
// }

