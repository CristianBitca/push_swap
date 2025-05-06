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

#include "pushswap.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (0);
	while (nb > (i * i))
		i++;
	if (nb == (i * i))
		return (i);
	else
		return (0);
}

void	chunk_info(int n, int *chunks, int *size)
{
	chunks = ft_sqrt(n) / 2;
	size = n / chunks;
}

void	chunk_sort(t_stack_list *stack_list)
{
	int	n_chunk;
	int	chunk_size;

	chunk_info(stack_list->a->size, &n_chunk, &chunk_size);
	printf("%d number of chunk\n %d size of chunk", n_chunk, chunk_size);
}
