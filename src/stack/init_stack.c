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

#include "../../include/pushswap.h"

void	swap(int *n1, int *n2)
{
	int	temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int	partition(int *array, int min, int max)
{
	int	pivot;
	int	i;
	int	j;

	i = (min - 1);
	pivot = array[max];
	j = min;
	while (j < max)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
		j++;
	}
	swap(&array[i + 1], &array[max]);
	return (i + 1);
}

void	quicksort(int *array, int min, int max)
{
	int	pi;

	if (min < max)
	{
		pi = partition(array, min, max);
		quicksort(array, min, pi - 1);
		quicksort(array, pi + 1, max);
	}
}

void	index_init(t_stack *stack)
{
	int	*array;
	int	i;
	t_node *cur;

	array = ft_calloc(sizeof(int), stack->size);
	i = -1;
	cur = stack->first;
	while (cur)
	{
		array[++i] = cur->n;
		cur = cur->next;
	}
	quicksort(array, 0, stack->size - 1);
	i = -1;
	while (++i < stack->size)
	{
		cur = stack->first;
		while (cur)
		{
			if (cur->n == array[i])
				cur->i = i;
			cur = cur->next;
		}
	}
	free(array);
}

t_stack_list	*init_stack_list(t_stack_list *stack_list, char **values)
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
	index_init(stack_list->a);
	return (stack_list);
}
