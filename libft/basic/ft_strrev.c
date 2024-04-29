/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:58:40 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/28 23:58:47 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_basic.h"

char	*ft_strrev(char *s)
{
	size_t	s_len;
	char	*tmp;
	char	*orig_tmp;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= 1)
		return (s);
	tmp = ft_strdup(s);
	if (!tmp)
		return (NULL);
	orig_tmp = tmp;
	while (s_len > 0)
	{
		s[s_len - 1] = *tmp;
		tmp++;
		s_len--;
	}
	free(orig_tmp);
	return (s);
}
