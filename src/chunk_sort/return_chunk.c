/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:56:32 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/09 14:56:33 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

int	short_way(t_stack *stack, int n)
{
	t_node	*node1;
	t_node	*node2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node1 = stack->first;
	node2 = stack->last;
	while (node1->i != n)
	{
		node1 = node1->next;
		i++;
	}
	while (node2->i != n)
	{
		node2 = node2->prev;
		j++;
	}
	if (j < i)
		return (1);
	return (0);
}

void	return_chunk(t_stack_list *stack_list, t_chunk *chunk, int i)
{
	int	max;
	int	way;
	int	count;

	count = 0;
	max = chunk->max - 1;
	while (count < chunk->size[i])
	{
		way = short_way(stack_list->b, max);
		if (stack_list->b->first->i == max)
		{
			pa(stack_list);
			count++;
			max--;
		}
		else if (way == 0)
			rb(stack_list);
		else
			rrb(stack_list);
	}
}

void	prev_chunk(t_chunk *chunk, int i)
{
	chunk->min -= chunk->size[i];
	chunk->max -= chunk->size[i];
}
