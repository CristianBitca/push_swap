/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:55:56 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/29 20:55:57 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rev_rotate_node(t_stack *stack)
{
	t_node *temp;

	temp = stack->last;
	stack->last = stack->last->prev;
	stack->last->next = NULL;
	stack->first->prev = temp;
    temp->next = stack->first;
    temp->prev = NULL;
	stack->first = temp;
}

void	rra(t_stack_list *stack_list)
{
	if (!stack_list || !stack_list->a || !stack_list->a->first || !stack_list->a->first->next)
		return ;
	rev_rotate_node(stack_list->a);
	ft_printf("rra\n");
	// print_stack(stack_list->a->first, stack_list->b->first);
}

void	rrb(t_stack_list *stack_list)
{
	if (!stack_list || !stack_list->b || !stack_list->b->first || !stack_list->b->first->next)
		return ;
	rev_rotate_node(stack_list->b);
	ft_printf("rrb\n");
	// print_stack(stack_list->a->first, stack_list->b->first);
}

void	rrr(t_stack_list *stack_list)
{
	if (!stack_list 
		|| !stack_list->b || !stack_list->b->first || !stack_list->b->first->next
		|| !stack_list->a || !stack_list->a->first || !stack_list->a->first->next)
		return ;
	rev_rotate_node(stack_list->a);
	rev_rotate_node(stack_list->b);
	ft_printf("rrr\n");
	// print_stack(stack_list->a->first, stack_list->b->first);
}