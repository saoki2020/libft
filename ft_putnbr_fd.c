/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 06:46:33 by saoki             #+#    #+#             */
/*   Updated: 2020/11/24 12:22:50 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		input_nbr(int n, char *nbr)
{
	int		i;

	i = 0;
	if (n < 0)
		n *= (-1);
	while (n != 0)
	{
		nbr[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	i = i - 1;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	nbr[20];

	i = input_nbr(n, nbr);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
		write(fd, "-", 1);
	while (i >= 0)
	{
		write(fd, &nbr[i], 1);
		i--;
	}
}
