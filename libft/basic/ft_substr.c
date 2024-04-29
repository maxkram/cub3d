/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:59:42 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/28 23:59:46 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_basic.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	max_sub_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		start = s_len;
	max_sub_len = s_len - start;
	if (len <= max_sub_len)
		sub = malloc(len + 1);
	else
		sub = malloc(max_sub_len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < max_sub_len && i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
