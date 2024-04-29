/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:49:20 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/29 00:18:27 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_basic.h"

static void	*ft_memcpyr(void *dst, const void *src, size_t n)
{
	while (n > 0)
	{
		((char *)dst)[n - 1] = ((char *)src)[n - 1];
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else if (dst > src)
	{
		ft_memcpyr(dst, src, len);
	}
	return (dst);
}
