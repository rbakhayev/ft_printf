/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:40:07 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/01 12:50:59 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

char	ft_check_flag(const char format, const char *str)
{
	if (format == '#')
	{
		if (*(str + 1) == 'x' || *(str + 1) == 'X')
			return (format);
		else
			return ('e');
	}
	else if (format == ' ')
	{
		if (*(str + 1) == 'd' || *(str + 1) == 'i')
			return (format);
		else
			return ('e');
	}
	else if (format == '+')
	{
		if (*(str + 1) == 'd' || *(str + 1) == 'i')
			return (format);
		else
			return ('e');
	}
	return ('e');
}

int	ft_check_type(va_list args, const char *str)
{
	int		print;
	char	flag;

	print = 0;
	flag = 'n';
	if (*str == '#' || *str == ' ' || *str == '+')
	{
		flag = ft_check_flag(*str, str);
		str++;
	}
	if (*str == 'c')
		print += ft_print_char(va_arg(args, int));
	else if (*str == 's')
		print += ft_print_str(va_arg(args, char *));
	else if (*str == 'p')
		print += ft_print_ptr(va_arg(args, long long unsigned));
	else if (*str == 'd' || *str == 'i')
		print += ft_print_num(va_arg(args, int), flag);
	else if (*str == 'u')
		print += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*str == 'x' || *str == 'X')
		print += ft_print_hexo(va_arg(args, unsigned int), *str, flag);
	else if (*str == '%')
		print += ft_printpercent();
	return (print);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print;

	print = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			print += ft_check_type(args, str + 1);
			if (*(str + 1) == '#' || *(str + 1) == ' ' || *(str + 1) == '+')
				str++;
			str++;
		}
		else
			print += ft_print_char(*str);
		str++;
	}
	va_end (args);
	return (print);
}
