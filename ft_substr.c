/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 01:01:48 by saoki             #+#    #+#             */
/*   Updated: 2020/11/24 12:18:17 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_len(size_t len, size_t start, size_t s_len)
{
	size_t	subs_len;

	if (len <= s_len - start)
		subs_len = len;
	else
		subs_len = s_len - start;
	return (subs_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len <= 0 || s_len < start)
		str = (char *)malloc(1);
	else
	{
		str = (char *)malloc(get_len(len, start, s_len) + 1);
		if (str == NULL)
			return (NULL);
		while (i < len && (start + i) < s_len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
