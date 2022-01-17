/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_long_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:22:43 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/31 13:33:33 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_pointer(char *str, t_list *flag)
{
	ft_prec(flag, "0x", 2);
	if (flag->dot < 0)
		ft_prec(flag, str, ft_strlen(str));
	else
	{
		ft_wdt(flag, flag->dot, ft_strlen(str), 1);
		ft_prec(flag, str, flag->dot);
	}
}

void	ft_point(t_list *flag)
{
	unsigned long long	n;
	char				*str;

	n = va_arg(flag->args, unsigned long long);
	if (n == 0 && flag->dot == 0)
	{
		if (flag->wdt && !flag->minus)
			ft_wdt(flag, flag->wdt, 2, 0);
		flag->len += write(1, "0x", 2);
		if (flag->wdt && flag->minus)
			ft_wdt(flag, flag->wdt, 2, 0);
	}
	else
	{
		str = ft_ull_base(n);
		str = ft_str_x(str);
		if ((size_t)flag->dot < ft_strlen(str))
			flag->dot = ft_strlen(str);
		if (flag->minus == 1)
			ft_put_pointer(str, flag);
		ft_wdt(flag, flag->wdt, ft_strlen(str) + 2, 0);
		if (flag->minus == 0)
			ft_put_pointer(str, flag);
		free(str);
	}
}
