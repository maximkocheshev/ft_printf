/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_integer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:29:20 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/01 11:01:01 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_putnbr_base(unsigned long long n_save, char *str, int i)
{
	while (n_save != 0)
	{
		if ((n_save % 16) < 10)
			str[i - 1] = (n_save % 16) + 48;
		else
			str[i - 1] = (n_save % 16) + 55;
		n_save /= 16;
		i--;
	}
	return (str);
}

char	*ft_ull_base(unsigned long long n)
{
	int					i;
	char				*str;
	unsigned long long	n_save;

	i = 0;
	n_save = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	str = ft_putnbr_base(n_save, str, i);
	return (str);
}

char	*ft_str_x(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

void	ft_put_part_str(char *str, t_list *flag)
{
	if (flag->minus == 1)
	{
		if (flag->dot >= 0)
			ft_wdt(flag, flag->dot - 1, ft_strlen(str) - 1, 1);
		ft_prec(flag, str, ft_strlen(str));
	}
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
	{
		if (flag->dot >= 0)
			ft_wdt(flag, flag->dot - 1, ft_strlen(str) - 1, 1);
		ft_prec(flag, str, ft_strlen(str));
	}
}

void	ft_int_x(t_list *flag, const char format)
{
	unsigned int	n;
	char			*str;

	n = va_arg(flag->args, unsigned int);
	if (flag->dot == 0 && n == 0)
		ft_wdt(flag, flag->wdt, 0, 0);
	else
	{
		str = ft_ull_base(n);
		if (format == 'x')
			str = ft_str_x(str);
		if (format == 'x' && flag->resh == 1 && n != 0)
			flag->len += write(1, "0x", 2);
		else if (format == 'X' && flag->resh == 1 && n != 0)
			flag->len += write(1, "0X", 2);
		ft_put_part_str(str, flag);
		free (str);
	}
}
