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
	t_node	*node;
	int		i;
	int		count;

	i = 0;
	count = 0;
	node = stack->first;
	while (count != stack->size / 2)
	{
		if (node->i >= min && node->i < max)
			i++;
		node = node->next;
		count++;
	}
	if (i > (max - min) / 2)
		return (0);
	return (1);
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
	int	way;

	count = 0;
	while (count < chunk->size[i])
	{
		way = chunk_way(stack_list->a, chunk->min, chunk->max);
		n = stack_list->a->first->i;
		if (in_range(n, chunk->min, chunk->max))
		{
			pb(stack_list);
			count++;
			if (n >= chunk->mid)
				rb(stack_list);
		}
		if (way == 0)
			ra(stack_list);
		else
			rra(stack_list);
	}
}
