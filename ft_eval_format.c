/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:11:32 by rbiodies          #+#    #+#             */
/*   Updated: 2021/12/15 19:51:20 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_flag(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') \
			|| (c == '*') || (c == '#') || (c == '+'));
}

t_list	*ft_bonus(t_list *flag, const char *format, int i)
{
	if (format[i] == '+')
		flag->plus = 1;
	if (format[i] == ' ')
		flag->sp = 1;
	if (format[i] == '#')
		flag->resh = 1;
	return (flag);
}

int	ft_treat_type(t_list *flag, const char *format, int i)
{
	if (flag->type == 0)
		return (0);
	i = ft_type(flag, format, i);
	return (i);
}

int	ft_eval_format(t_list *flag, const char *format, int i)
{
	while (format[i])
	{
		if (!ft_is_type(format[i]) && !ft_is_flag(format[i]) \
				&& !(format[i] >= '0' && format[i] <= '9'))
			break ;
		flag = ft_bonus(flag, format, i);
		if (format[i] == '0' && !flag->wdt && !flag->minus)
			flag->zero = 1;
		if (format[i] == '.')
			i = ft_dot(flag, format, i);
		if (format[i] == '-')
			flag = ft_minus(flag);
		if (format[i] == '*')
			flag = ft_star(flag);
		if (format[i] >= '0' && format[i] <= '9')
			flag = ft_digit(flag, format[i]);
		if (ft_is_type(format[i]))
		{
			flag->type = format[i];
			break ;
		}
		i++;
	}
	i = ft_treat_type(flag, format, i);
	return (i);
}
