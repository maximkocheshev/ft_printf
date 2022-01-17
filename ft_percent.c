/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:20:22 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/29 11:52:47 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_percent(t_list *flag)
{
	if (flag->minus)
		ft_prec(flag, "%", 1);
	ft_wdt(flag, flag->wdt, 1, flag->zero);
	if (!flag->minus)
		ft_prec(flag, "%", 1);
}
