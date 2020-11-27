/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saoki <saoki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:17:11 by saoki             #+#    #+#             */
/*   Updated: 2020/11/24 12:04:15 by saoki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_str_number(char *str, char c)
{
	int		i;
	int		str_number;

	i = 0;
	str_number = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != c)
		{
			str_number++;
			i++;
		}
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			str_number++;
		i++;
	}
	return (str_number);
}

static void	all_free(char **str, int array_num)
{
	int		i;

	i = 0;
	while (i < array_num)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	fill_str_array(char *s, char c, int str_number, char **str_array)
{
	int		i;
	int		array_num;
	int		start_index;

	array_num = 0;
	i = 0;
	while (array_num < str_number)
	{
		while (s[i] == c)
			i++;
		start_index = i;
		while (s[i] != c)
			i++;
		str_array[array_num] = ft_substr(s, start_index, i - start_index);
		if (str_array[array_num] == NULL)
		{
			all_free(str_array, array_num);
			return ;
		}
		array_num++;
		i++;
	}
	str_array[array_num] = NULL;
}

char		**ft_split(char const *s, char c)
{
	int			str_number;
	char		**str_array;

	if (s == NULL)
		return (NULL);
	str_number = count_str_number((char *)s, c);
	str_array = malloc((str_number + 1) * sizeof(char *));
	if (str_array == NULL)
		return (NULL);
	fill_str_array((char *)s, c, str_number, str_array);
	return (str_array);
}
