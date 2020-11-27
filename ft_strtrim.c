/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:14:11 by saoki             #+#    #+#             */
/*   Updated: 2020/11/27 23:49:38 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		front_set(char *str, char *set)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

int		back_set(char *str, char *set)
{
	int		size;

	size = ft_strlen(str);
	while (size >= 0)
	{
		if (ft_strrchr(set, str[size]) == NULL)
			break ;
		size--;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		iend;
	int		istart;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	istart = front_set((char *)s1, (char *)set);
	iend = back_set((char *)s1, (char *)set);
	str = ft_substr(s1, istart, (iend - istart + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}
