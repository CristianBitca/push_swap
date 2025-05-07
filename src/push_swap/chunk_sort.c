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
	else if (size <= 400)
		return (12);
	else
		return (ft_sqrt(size) / 2);
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
			if (n <= chunk->mid)
				rb(stack_list);
			count++;
		}
		else
			ra(stack_list);
	}
}

void	return_chunk(t_stack_list *stack_list, t_chunk *chunk, int i)
{
	int	max;
	int	count;

	count = 0;
	max = chunk->max - 1;
	while (count < chunk->size[i])
	{
		if (stack_list->b->first->i == max)
		{
			pa(stack_list);
			count++;
			max--;
		}
		else
			rb(stack_list);
	}
}

void	next_chunk(t_chunk *chunk, int i)
{
	chunk->min += chunk->size[i];
	i++;
	chunk->max += chunk->size[i];
	chunk->mid = (chunk->min + chunk->max) / 2;
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
		return_chunk(stack_list, chunk, i);
		next_chunk(chunk, i);
		i++;
	}
	free(chunk->size);
	free(chunk);
}
