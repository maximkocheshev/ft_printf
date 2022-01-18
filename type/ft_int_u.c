/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int_10.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:57:25 by rbiodies          #+#    #+#             */
/*   Updated: 2021/10/29 16:00:26 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_putnbru_fd(char *str, unsigned int n, int len, int i)
{
	i = 0;
	if (n != 0)
		str = (char *)malloc(len + 1);
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (i == 1)
		str[0] = '-';
	else
		str[0] = (n % 10) + '0';
	return (str);
}

void	ft_in_put_u(char *str, t_list *flag)
{
	if (flag->dot >= 0)
		ft_wdt(flag, flag->dot - 1, ft_strlen(str) - 1, 1);
	ft_prec(flag, str, ft_strlen(str));
}

void	ft_put_u(char *str, t_list *flag)
{
	if (flag->minus == 1)
		ft_in_put_u(str, flag);
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
		ft_in_put_u(str, flag);
}

void	ft_int_u(t_list *flag)
{
	unsigned int	n;
	char			*str;
	int				i;
	int				len;

	i = 0;
	str = 0;
	n = va_arg(flag->args, unsigned int);
	if (flag->dot == 0 && n == 0)
		ft_wdt(flag, flag->wdt, 0, 0);
	else
	{
		len = ft_len(n);
		str = ft_putnbru_fd(str, n, len, i);
		ft_put_u(str, flag);
		free(str);
	}
}
