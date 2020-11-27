/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:37:17 by saoki             #+#    #+#             */
/*   Updated: 2020/11/27 23:33:12 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	overflow_test(unsigned long long result, int fugo)
{
	if (fugo >= 0)
	{
		if (result > LLONG_MAX)
			return (-1);
	}
	if (fugo < 0)
	{
		if ((result - 1) > LLONG_MAX)
			return (0);
	}
	return (result);
}

int					ft_atoi(const char *str)
{
	unsigned long long int	result;
	int						i;
	int						fugo;

	i = 0;
	fugo = 1;
	result = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||\
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			fugo *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = overflow_test(result, fugo);
	return ((int)(result * fugo));
}
