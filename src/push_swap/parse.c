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

void    init_stack(t_stack *stack, int n, char **values)
{
    int i;

    i = 1;
    while (i < n)
    {
	while (*values[i])
	{
		if (*values[i] == ' ' || ('\t' <= *values[i] && '\r' >= *values[i]))
			i++;
		if (*values[i] == '-' || *values[i] == '+')
			i++;
		printf("%ld\n", ps_atoi(values[i]));
		values[i]++;
	}
	i++;
    }
    printf("\n");
    stack = 0;
}
