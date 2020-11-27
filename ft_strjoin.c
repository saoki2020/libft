/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 23:24:07 by saoki             #+#    #+#             */
/*   Updated: 2020/11/27 21:45:20 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_str;
	char	*str;

	if (s1 == NULL && s2 == NULL)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	else
	{
		len_str = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(len_str + 1);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, (char *)s1, (ft_strlen(s1) + 1));
		ft_strlcat(str, (char *)s2, (len_str + 1));
		return (str);
	}
}
