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

t_node *new_node(int num)
{
	t_node *node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (0);
	node->n = num;
	return (node);
}

void	append_stack(t_node **node_lst, t_node *new)
{
	if (node_lst)
	{
		if (*node_lst)
		{
			stack_last(*node_lst)->next = new;
			new->prev = *node_lst;
		}
		else
			*node_lst = new;
	}
}

t_node	*stack_last(t_node *first)
{
	t_node *node;

	node = first;
	if (!node)
		return (0);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

int	stack_size(t_node *node)
{
	int	i;

	i = 0;
	if (!node)
		return (i);
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	print_stack(t_node *node_lst)
{
	while (node_lst)
	{
		ft_printf("%d\n", node_lst->n);
		node_lst = node_lst->next;
	}
}

