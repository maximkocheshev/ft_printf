/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:47:05 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/31 13:15:12 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wdt(t_list *flag, int wdt, int minus, int has_zero)
{
	while (wdt - minus > 0)
	{
		if (has_zero)
			flag->len += write(1, "0", 1);
		else
			flag->len += write(1, " ", 1);
		wdt--;
	}
}
