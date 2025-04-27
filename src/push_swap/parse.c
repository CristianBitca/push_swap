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

long int	ps_atoi(const char *nptr)
{
	int	i;
	long int	sign;
	long int	result;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == ' ' || ('\t' <= nptr[i] && '\r' >= nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ('0' <= nptr[i] && '9' >= nptr[i])
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

void	split_value(t_stack_list *stack_list, t_stack *stack, const char *value)
{
	int		i;
	long int	num;

	i = 0;
	if (!ft_strlen(value) || !value)
		print_error(stack_list, INT_ERROR);
	while (value[i])
	{
		if (value[i] == ' ' || ('\t' <= value[i] && '\r' >= value[i]))
			i++;
		if (value[i] == '+' || value[i] == '-')
			i++;
		if (i == 0 && ('0' <= value[i] && '9' >= value[i]))
			num = ps_atoi(&value[i]);
		else if ('0' <= value[i] && '9' >= value[i])
			num = ps_atoi(&value[i - 1]);
		else
			print_error(stack_list, INT_ERROR);
		if (num > MAX_INT || num < MIN_INT)
			print_error(stack_list, INT_OVERFLOW);
		append_stack(stack, num);
		while ('0' <= value[i] && '9' >= value[i])
			i++;
	}
}

void	parse_data(t_stack_list *stack_list, t_stack *stack, char **values)
{
	if (!values)
		print_error(stack_list, 0);
	stack->first = NULL;
	while (*values)
	{
		split_value(stack_list, stack, *values);
		values++;
	}
}
