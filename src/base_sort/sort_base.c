/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:02:09 by cbitca            #+#    #+#             */
/*   Updated: 2025/05/05 19:02:10 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	sort_two(t_stack_list *stack_list)
{
	if (stack_list->a->first->i > stack_list->a->first->next->i)
		sa(stack_list);
}

void	sort_three(t_stack_list *stack_list, int max)
{
	if (stack_list->a->first->i == max - 1)
		ra(stack_list);
	else
		sa(stack_list);
	if (!is_sorted(stack_list->a))
		sort_three(stack_list, max);
}

void	sort_five(t_stack_list *stack_list, int min, int max)
{
	while (stack_list->a->first->i != min)
		ra(stack_list);
	pb(stack_list);
	if (stack_list->a->size == 3)
		sort_three(stack_list, max);
	else
		sort_five(stack_list, ++min, max);
	pa(stack_list);
}
