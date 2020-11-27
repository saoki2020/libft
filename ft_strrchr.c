/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:29:28 by saoki             #+#    #+#             */
/*   Updated: 2020/11/24 13:13:58 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		size;
	char	*str;

	str = (char*)s;
	size = ft_strlen(str);
	while (size >= 0)
	{
		if (str[size] == c)
			return (&str[size]);
		size--;
	}
	return (NULL);
}
