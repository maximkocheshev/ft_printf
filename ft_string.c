/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:10:15 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/31 13:07:22 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_string(t_list *flag, char *str)
{
	if (flag->dot >= 0)
	{
		ft_wdt(flag, flag->dot, ft_strlen(str), 0);
		ft_prec(flag, str, flag->dot);
	}
	else
		ft_prec(flag, str, ft_strlen(str));
}

void	ft_string(t_list *flag)
{
	char	*str;

	str = va_arg(flag->args, char *);
	if (!str)
		str = "(null)";
	if (flag->dot >= 0 && (size_t)flag->dot >= ft_strlen(str))
		flag->dot = ft_strlen(str);
	if (flag->minus == 1)
		ft_put_string(flag, str);
	if (flag->dot >= 0)
		ft_wdt(flag, flag->wdt, flag->dot, 0);
	else
		ft_wdt(flag, flag->wdt, ft_strlen(str), flag->zero);
	if (flag->minus == 0)
		ft_put_string(flag, str);
}
