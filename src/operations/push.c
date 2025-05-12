/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:55:47 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/29 20:55:48 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pa(t_stack_list *stack_list)
{
	t_node	*temp;

	if (!stack_list || !stack_list->b || !stack_list->b->first)
		return ;
	temp = stack_list->b->first;
	stack_list->b->first = stack_list->b->first->next;
	if (stack_list->b->first)
		stack_list->b->first->prev = NULL;
	else
		stack_list->b->last = NULL;
	stack_list->b->size--;
	temp->next = stack_list->a->first;
	if (stack_list->a->first)
		stack_list->a->first->prev = temp;
	else
		stack_list->a->last = temp;
	stack_list->a->first = temp;
	stack_list->a->size++;
	ft_printf("pa\n");
}

void	pb(t_stack_list *stack_list)
{
	t_node	*temp;

	if (!stack_list || !stack_list->a || !stack_list->a->first)
		return ;
	temp = stack_list->a->first;
	stack_list->a->first = stack_list->a->first->next;
	if (stack_list->a->first)
		stack_list->a->first->prev = NULL;
	else
		stack_list->a->last = NULL;
	stack_list->a->size--;
	temp->next = stack_list->b->first;
	if (stack_list->b->first)
		stack_list->b->first->prev = temp;
	else
		stack_list->b->last = temp;
	stack_list->b->first = temp;
	stack_list->b->size++;
	ft_printf("pb\n");
}
