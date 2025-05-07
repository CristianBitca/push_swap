/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:01:17 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/05 16:01:18 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	sort_stack(t_stack_list *stack_list)
{
	if (stack_list->a->size == 2)
		sort_two(stack_list);
	else if (stack_list->a->size == 3)
		sort_three(stack_list, stack_list->a->size);
	else if (stack_list->a->size == 5 || stack_list->a->size == 4)
		sort_five(stack_list, 0, stack_list->a->size);
	else if (stack_list->a->size > 5)
		chunk_sort(stack_list);
	// print_stack(stack_list->a->first, stack_list->b->first);
}
