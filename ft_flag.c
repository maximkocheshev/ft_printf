/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:56:53 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/31 13:58:37 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dot(t_list *flag, const char *format, int i)
{
	i++;
	if (format[i] == '*')
	{
		flag->dot = va_arg(flag->args, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (format[i] >= '0' && format[i] <= '9')
		{
			flag->dot = flag->dot * 10 + (format[i] - '0');
			i++;
		}
	}
	return (i);
}

t_list	*ft_minus(t_list *flag)
{
	flag->minus = 1;
	flag->zero = 0;
	return (flag);
}

t_list	*ft_star(t_list *flag)
{
	flag->star = 1;
	flag->wdt = va_arg(flag->args, int);
	if (flag->wdt < 0)
	{
		flag->minus = 1;
		flag->wdt *= -1;
		flag->zero = 0;
	}
	return (flag);
}

t_list	*ft_digit(t_list *flag, const char format)
{
	if (flag->star == 1)
		flag->wdt = 0;
	flag->wdt = flag->wdt * 10 + (format - '0');
	return (flag);
}
