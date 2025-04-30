/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:56:04 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/29 20:56:09 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack_list *stack_list)
{
	t_node *temp;

	if (!stack_list || !stack_list->a || !stack_list->a->first || !stack_list->a->first->next)
		return ;
	temp = stack_list->a->first;
	stack_list->a->first = stack_list->a->first->next;
	if (stack_list->a->first)
		stack_list->a->first->prev = NULL;
	else
		stack_list->a->last = NULL;
	temp->next = NULL;
	if (stack_list->a->last)
		stack_list->a->last->next = temp;
	else
		stack_list->a->last = temp;
	stack_list->a->last = temp;
	printf("ra\n");
	print_stack(stack_list->a->first, stack_list->b->first);
}

void	rb(t_stack_list *stack_list)
{
	t_node *temp;

	if (!stack_list || !stack_list->b || !stack_list->b->first || !stack_list->b->first->next)
		return ;
	temp = stack_list->b->first;
	stack_list->b->first = stack_list->b->first->next;
	if (stack_list->b->first)
		stack_list->a->first->prev = NULL;
	else
		stack_list->b->last = NULL;
	temp->next = NULL;
	if (stack_list->b->last)
		stack_list->b->last->next = temp;
	else
		stack_list->b->last = temp;
	stack_list->b->last = temp;
	printf("ra\n");
	print_stack(stack_list->a->first, stack_list->b->first);
}

void	rr(t_stack_list *stack_list)
{
	
}