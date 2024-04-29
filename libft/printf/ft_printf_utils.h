/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:08:21 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/29 00:20:43 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>

int	ft_int_putchar_fd(char c, int fd);
int	ft_int_putstr_fd(char *s, int fd);
int	ft_int_putnbr_fd(int n, int fd);
int	ft_int_putnbr_uint_fd(unsigned int n, int fd);

#endif
