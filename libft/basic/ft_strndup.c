/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:57:08 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/28 23:57:11 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_basic.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*p;
	size_t	i;

	p = ft_calloc(n + 1, 1);
	if (!p)
		return (0);
	p[n] = '\0';
	i = 0;
	while (s1[i] && i < n)
	{
		p[i] = s1[i];
		i++;
	}
	return (p);
}
