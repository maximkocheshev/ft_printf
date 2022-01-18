/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:16:14 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/01 13:29:05 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(t_list *flag)
{
	char	ch;

	ch = va_arg(flag->args, int);
	if (flag->minus == 1)
		flag->len += write(1, &ch, 1);
	ft_wdt(flag, flag->wdt, 1, 0);
	if (flag->minus == 0)
		flag->len += write(1, &ch, 1);
}
