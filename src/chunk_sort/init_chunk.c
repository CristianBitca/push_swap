/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:45:57 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/09 14:45:58 by cbitca           ###   ########.fr       */
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

void	chunk_size(t_chunk *chunk, int size)
{
	int	i;
	int	rest;

	i = 0;
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
}

t_chunk	*init_chunk(t_stack_list *stack_list, t_chunk *chunk)
{
	chunk->number = chunk_number(stack_list->a->size);
	chunk->size = ft_calloc(sizeof(int *), chunk->number);
	chunk_size(chunk, stack_list->a->size);
	chunk->max = chunk->size[0];
	chunk->mid = (chunk->min + chunk->max) / 2;
	return (chunk);
}
