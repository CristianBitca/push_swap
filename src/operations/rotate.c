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

void	rotate_node(t_stack *stack)
{
	t_node *temp;

	temp = stack->first;
	stack->first = stack->first->next;
	stack->first->prev = NULL;
	stack->last->next = temp;
	temp->prev = stack->last;
	temp->next = NULL;
	stack->last = temp;
}

void	ra(t_stack_list *stack_list)
{
	if (!stack_list || !stack_list->a || !stack_list->a->first || !stack_list->a->first->next)
		return ;
	rotate_node(stack_list->a);
	ft_printf("ra\n");
	// print_stack(stack_list->a->first, stack_list->b->first);
}

void	rb(t_stack_list *stack_list)
{
	if (!stack_list || !stack_list->b || !stack_list->b->first || !stack_list->b->first->next)
		return ;
	rotate_node(stack_list->b);
	ft_printf("rb\n");
	// print_stack(stack_list->a->first, stack_list->b->first);
}

void	rr(t_stack_list *stack_list)
{
	if (!stack_list 
		|| !stack_list->b || !stack_list->b->first || !stack_list->b->first->next
		|| !stack_list->a || !stack_list->a->first || !stack_list->a->first->next)
		return ;
	rotate_node(stack_list->a);
	rotate_node(stack_list->b);
	ft_printf("rr\n");
	// print_stack(stack_list->a->first, stack_list->b->first);
}
