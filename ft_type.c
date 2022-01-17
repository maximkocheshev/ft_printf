/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:41:01 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/31 13:38:17 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || \
			(c == 'i') || (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_type(t_list *flag, const char *format, int i)
{
	if (format[i] == 'c')
		ft_char(flag);
	if (format[i] == 's')
		ft_string(flag);
	if (format[i] == 'p')
		ft_point(flag);
	if (format[i] == 'd' || format[i] == 'i')
		ft_int(flag);
	if (format[i] == 'u')
		ft_int_u(flag);
	if (format[i] == 'x' || format[i] == 'X')
		ft_int_x(flag, format[i]);
	if (format[i] == '%')
		ft_percent(flag);
	return (i);
}
