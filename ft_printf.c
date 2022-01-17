/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:17:29 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/03 18:12:17 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_init_flag(t_list *flag)
{
	flag->type = 0;
	flag->wdt = 0;
	flag->zero = 0;
	flag->dot = -1;
	flag->len = 0;
	flag->minus = 0;
	flag->star = 0;
	flag->resh = 0;
	flag->sp = 0;
	flag->plus = 0;
	return (flag);
}

int	ft_treat(t_list *flag, const char *format)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (format[i])
	{
		flag->type = 0;
		flag->wdt = 0;
		flag->zero = 0;
		flag->dot = -1;
		flag->minus = 0;
		flag->star = 0;
		flag->resh = 0;
		flag->sp = 0;
		flag->plus = 0;
		if (format[i] == '%' && format[i + 1])
		{
			i = ft_eval_format(flag, format, ++i);
		}
		else
			res += write(1, &format[i], 1);
		i++;
	}
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	t_list	*flag;

	flag = (t_list *)malloc(sizeof(t_list));
	if (!flag)
		return (-1);
	ft_init_flag(flag);
	va_start(flag->args, format);
	res = ft_treat(flag, format);
	va_end(flag->args);
	res += flag->len;
	free (flag);
	return (res);
}
