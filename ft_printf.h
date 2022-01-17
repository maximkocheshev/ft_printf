/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbiodies <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:19:20 by rbiodies          #+#    #+#             */
/*   Updated: 2021/11/03 18:12:30 by rbiodies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	va_list	args;
	int		type;
	int		wdt;
	int		zero;
	int		dot;
	int		minus;
	int		star;
	int		len;
	int		perc;
	int		resh;
	int		sp;
	int		plus;
}	t_list;

int		ft_printf(const char *format, ...);
t_list	*ft_init_flag(t_list *flag);
int		ft_eval_format(t_list *flag, const char *format, int i);
void	ft_char(t_list *flag);
void	ft_string(t_list *flag);
void	ft_int(t_list *flag);
void	ft_point(t_list *flag);
void	ft_int_x(t_list *flag, const char format);
void	ft_int_u(t_list *flag);
char	*ft_itoa(long long int n);
size_t	ft_strlen(const char *s);
void	ft_wdt(t_list *flag, int wdt, int minus, int has_zero);
void	ft_prec(t_list *flag, char *str, int prec);
void	ft_percent(t_list *flag);
int		ft_len(long nb);
char	*ft_strdup(const char *s1);
int		ft_tolower(int c);
char	*ft_ull_base(unsigned long long n);
char	*ft_str_x(char *str);
int		ft_type(t_list *flag, const char *format, int i);
int		ft_dot(t_list *flag, const char *format, int i);
t_list	*ft_minus(t_list *flag);
t_list	*ft_star(t_list *flag);
t_list	*ft_digit(t_list *flag, const char format);
int		ft_is_type(int c);

#endif
