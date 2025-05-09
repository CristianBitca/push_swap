/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:54:29 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/09 14:54:30 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

int	chunk_way(t_stack *stack, int min, int max)
{
	t_node *node1;
	t_node *node2;
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	node1 = stack->first;
	node2 = stack->last;
	while (count != stack->size / 2)
	{
		if (node1->i >= min && node1->i < max)
			i++;
		node1 = node1->next;
		count++;
	}
	while (count != stack->size)
	{
		if (node2->i >= min && node2->i < max)
			j++;
		node2 = node2->prev;
		count++;
	}
	if (j < i)
		return (1);
	return (0);
}

void	next_chunk(t_chunk *chunk, int i)
{
	chunk->min += chunk->size[i];
	i++;
	chunk->max += chunk->size[i];
	chunk->mid = (chunk->min + chunk->max) / 2;
}

void	sorting_chunk(t_stack_list *stack_list, t_chunk *chunk, int i)
{
	int	count;
	int	n;

	count = 0;
	while (count < chunk->size[i])
	{
		n = stack_list->a->first->i;
		if (n >= chunk->min && n < chunk->max)
		{
			pb(stack_list);
			count++;
			if (n >= chunk->mid)
				rb(stack_list);
		}
		else
			ra(stack_list);

	}
}
