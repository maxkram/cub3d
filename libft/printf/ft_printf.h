/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkramer <mkramer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 00:07:38 by mkramer           #+#    #+#             */
/*   Updated: 2024/04/29 00:07:41 by mkramer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# include "../libft.h"

# include "ft_printf_utils.h"
# include "ft_printf_spec_hex.h"

int		ft_printf(const char *input, ...);

#endif
