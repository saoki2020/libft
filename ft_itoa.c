/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:56:19 by saoki             #+#    #+#             */
/*   Updated: 2020/11/24 12:19:49 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		num_change(int n, char *str)
{
	int		i;
	char	fugo;

	i = 0;
	if (n <= 0)
	{
		str[i] = n % 10 * (-1) + '0';
		if (n < 0)
			fugo = '-';
		n = n / 10 * (-1);
		i++;
	}
	while (n != 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	if (fugo == '-')
	{
		str[i] = '-';
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	char	num[20];

	len = num_change(n, num);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		str[i] = num[len - 1];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
