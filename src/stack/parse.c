/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:28:20 by cbitca            #+#    #+#             */
/*   Updated: 2025/04/25 21:25:35 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

long int	ps_atoi(t_stack_list *stack_list, const char *nptr)
{
	long int	sign;
	long int	result;
	int			i;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == ' ' || ('\t' <= nptr[i] && '\r' >= nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(nptr[i]))
		print_error(stack_list, INT_ERROR);
	while (ft_isdigit(nptr[i]))
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	check_duplicates(t_stack_list *stack_list, t_node *node, int num)
{
	while (node)
	{
		if (node->n == num)
			print_error(stack_list, INT_DUP);
		node = node->next;
	}
}

int	next_int(const char *value, int i)
{
	if (value[i] == ' ' || ('\t' <= value[i] && '\r' >= value[i]))
		i++;
	if (value[i] == '+' || value[i] == '-')
		i++;
	while (ft_isdigit(value[i]))
		i++;
	if (value[i] == ' ' || ('\t' <= value[i] && '\r' >= value[i]))
		i++;
	return (i);
}

void	split_value(t_stack_list *stack_list, t_stack *stack, const char *value)
{
	int			i;
	long int	num;

	i = 0;
	if (!ft_strlen(value) || !value)
		print_error(stack_list, 0);
	while (value[i])
	{
		num = ps_atoi(stack_list, &value[i]);
		if (num > INT_MAX || num < INT_MIN)
			print_error(stack_list, INT_OVERFLOW);
		check_duplicates(stack_list, stack->first, num);
		append_stack(&stack->first, new_node(num));
		i = next_int(value, i);
	}
}

void	parse_data(t_stack_list *stack_list, t_stack *stack, char **values)
{
	if (!values)
		print_error(stack_list, 0);
	while (*values)
	{
		split_value(stack_list, stack, *values);
		values++;
	}
}
