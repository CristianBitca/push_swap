/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:38:48 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/05 16:38:49 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	cur = stack->first;
	while (cur->next)
	{
		if (cur->n < cur->next->n)
			cur = cur->next;
		else
			return (0);
	}
	return (1);
}

void	push_swap(t_stack_list *stack_list, char **values)
{
	stack_list = init_stack_list(stack_list, &values[1]);
	if (!is_sorted(stack_list->a))
		sort_stack(stack_list);
	free_stack_list(stack_list);
}
