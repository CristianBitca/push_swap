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

t_node	*new_node(int num)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (0);
	node->n = num;
	return (node);
}

void	append_stack(t_node **node_lst, t_node *new)
{
	t_node	*temp;

	if (node_lst)
	{
		if (*node_lst)
		{
			temp = stack_last(*node_lst);
			temp->next = new;
			new->prev = temp;
		}
		else
			*node_lst = new;
	}
}

t_node	*stack_last(t_node *first)
{
	t_node	*node;

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

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			ft_printf("%d | %d\n", stack_a->i, stack_b->i);
			stack_b = stack_b->next;
			stack_a = stack_a->next;
		}
		else if (stack_a)
		{
			ft_printf("%d | \n", stack_a->i);
			stack_a = stack_a->next;
		}
		else if (stack_b)
		{
			ft_printf("  | %d\n", stack_b->i);
			stack_b = stack_b->next;
		}
	}
}
