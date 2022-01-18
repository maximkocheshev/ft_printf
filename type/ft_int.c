/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:27:24 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/01 11:55:47 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_in_put_int(char *str, int save_a, t_list *flag)
{
	if (save_a < 0 && flag->dot >= 0)
		flag->len += write(1, "-", 1);
	if (flag->dot >= 0)
		ft_wdt(flag, flag->dot - 1, ft_strlen(str) - 1, 1);
	ft_prec(flag, str, ft_strlen(str));
}

void	ft_put_int(char *str, int save_a, t_list *flag)
{
	if (flag->minus == 1)
		ft_in_put_int(str, save_a, flag);
	if (flag->dot >= 0 && (size_t)flag->dot < ft_strlen(str))
		flag->dot = ft_strlen(str);
	if (flag->dot >= 0)
	{
		flag->wdt -= flag->dot;
		ft_wdt(flag, flag->wdt, 0, 0);
	}
	else
		ft_wdt(flag, flag->wdt, ft_strlen(str), flag->zero);
	if (flag->minus == 0)
		ft_in_put_int(str, save_a, flag);
}

t_list	*ft_check(t_list *flag, int save_a)
{
	if (save_a < 0)
		flag->sp = 0;
	else if (flag->plus == 1)
		ft_prec(flag, "+", 1);
	if (flag->sp == 1)
		ft_prec(flag, " ", 1);
	return (flag);
}

void	ft_int(t_list *flag)
{
	long long int	a;
	char			*str;
	int				i;
	int				save_a;

	i = 0;
	a = va_arg(flag->args, int);
	save_a = a;
	if (flag->dot == 0 && a == 0)
		ft_wdt(flag, flag->wdt, 0, 0);
	else
	{
		if (a < 0 && (flag->dot >= 0 || flag->zero == 1))
		{
			if (flag->zero == 1 && flag->dot < 0)
				ft_prec(flag, "-", 1);
			a *= -1;
			flag->zero = 1;
			flag->wdt--;
		}
		flag = ft_check(flag, save_a);
		str = ft_itoa(a);
		ft_put_int(str, save_a, flag);
		free(str);
	}
}
