/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:41:18 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/26 18:41:19 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init_stack_list(t_stack_list *stack_list, char **values)
{
	stack_list = ft_calloc(sizeof(t_stack_list), 1);
	if (!stack_list)
		print_error(stack_list, 0);
	stack_list->a = ft_calloc(sizeof(t_stack), 1);
	stack_list->b = ft_calloc(sizeof(t_stack), 1);
	if (!stack_list->a || !stack_list->b)
		print_error(stack_list, 0);
	parse_data(stack_list, stack_list->a, values);
	stack_list->a->last = stack_last(stack_list->a->first);
	stack_list->a->size = stack_size(stack_list->a->first);
	print_stack(stack_list->a->first, stack_list->b->first);
	ra(stack_list);
}
