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
		print_stack(stack_list->a->first, stack_list->b->first);
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
