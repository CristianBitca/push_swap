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

int	in_range(int n, int min, int max)
{
	if (n >= min && n < max)
		return (1);
	return (0);
}

void	chunk_sort(t_stack_list *stack_list)
{
	t_chunk	*chunk;
	int		i;

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
