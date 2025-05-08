/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:31:30 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/06 19:31:31 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (0);
	while (nb >= (i * i))
		i++;
	return (i);
}

int	chunk_number(int size)
{
	if (size <= 20)
		return (2);
	else if (size <= 100)
		return (5);
	else if (size <= 200)
		return (8);
	else if (size <= 300)
		return (10);
	else
		return ((ft_sqrt(size) / 2) - 1);
}

t_chunk	*init_chunk(t_stack_list *stack_list, t_chunk *chunk)
{
	int	size;
	int	i;
	int	rest;

	i = 0;
	size = stack_list->a->size;
	chunk->number = chunk_number(size);
	chunk->size = ft_calloc(sizeof(int *), chunk->number);
	while (i < chunk->number)
	{
		chunk->size[i] = size / chunk->number;
		i++;
	}
	rest = size % chunk->number;
	i = 0;
	while (rest)
	{
		chunk->size[i]++;
		if (i == chunk->number)
			i = 0;
		else
			i++;
		rest--;
	}
	chunk->max = chunk->size[0];
	chunk->mid = (chunk->min + chunk->max) / 2;
	return (chunk);
}

int	short_way(t_stack *stack, int n)
{
	t_node *node1;
	t_node *node2;
	int	i;
	int	j;

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
			if (n >= chunk->mid)
			{
				if (stack_list->a->first->next->i >= chunk->min
					&& stack_list->a->first->i < chunk->max)
					rb(stack_list);
				else
					rr(stack_list);
			}
			count++;
		}
		else
			ra(stack_list);

	}
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

void	next_chunk(t_chunk *chunk, int i)
{
	chunk->min += chunk->size[i];
	i++;
	chunk->max += chunk->size[i];
	chunk->mid = (chunk->min + chunk->max) / 2;
}

void	prev_chunk(t_chunk *chunk, int i)
{
	chunk->min -= chunk->size[i];
	chunk->max -= chunk->size[i];
}

void	chunk_sort(t_stack_list *stack_list)
{
	t_chunk *chunk;
	int	i;

	i = 0;
	chunk = ft_calloc(sizeof(t_chunk), 1);
	chunk = init_chunk(stack_list, chunk);
	while (i < chunk->number)
	{
		sorting_chunk(stack_list, chunk, i);
		next_chunk(chunk, i);
		i++;
	}
	while (stack_list->b->size)
	{
		return_chunk(stack_list, chunk, i);
		prev_chunk(chunk, i);
		i--;
	}
	free(chunk->size);
	free(chunk);
}
