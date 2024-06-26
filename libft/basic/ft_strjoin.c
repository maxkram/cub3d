/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:54:24 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/28 23:54:26 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_basic.h"

static char	*init_joined_string(const char *s1, const char *s2)
{
	size_t	new_str_len;
	char	*new_string;

	new_str_len = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc(new_str_len + 1);
	if (!new_string)
		return (0);
	new_string[new_str_len] = 0;
	return (new_string);
}

static void	join_string(char *joined_str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		joined_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joined_str[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;

	if (!s1 || !s2)
		return (0);
	new_string = init_joined_string(s1, s2);
	if (!new_string)
		return (0);
	join_string(new_string, s1, s2);
	return (new_string);
}
