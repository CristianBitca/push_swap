/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:56:18 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/29 20:56:19 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_int(t_node *node1, t_node *node2)
{
	int	temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
	temp = node1->i;
	node1->i = node2->i;
	node2->i = temp;
}

void	sa(t_stack_list *stack_list)
{
	swap_int(stack_list->a->first, stack_list->a->first->next);
	ft_printf("sa\n");
}

void	sb(t_stack_list *stack_list)
{
	swap_int(stack_list->b->first, stack_list->b->first->next);
	ft_printf("sb\n");
}

void	ss(t_stack_list *stack_list)
{
	swap_int(stack_list->a->first, stack_list->a->first->next);
	swap_int(stack_list->b->first, stack_list->b->first->next);
	ft_printf("ss\n");
}
