/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 11:46:56 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/01 11:54:12 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_controlla(const char format, char d, int *s, int i)
{
	while (i >= 0)
	{
		if (s[i] >= 0 && s[i] <= 9)
		{
			d = s[i] + '0';
			write(1, &d, 1);
		}
		else
		{
			if (format == 'x')
			{
				d = s[i] + 87;
				write(1, &d, 1);
			}
			if (format == 'X')
			{
				d = s[i] + 55;
				write(1, &d, 1);
			}
		}
		i--;
	}
	free (s);
}

int	ft_check_hexo_flag(const char format, char flag)
{
	int	len;

	len = 0;
	if (format == 'x' && flag == '#')
	{
		write(1, "0x", 2);
		len += 2;
	}
	else if (format == 'X' && flag == '#')
	{
		write(1, "0X", 2);
		len += 2;
	}
	return (len);
}

int	ft_put_hexo(unsigned int num, const char format, char flag)
{
	char	d;
	int		*s;
	int		i;
	int		len;

	d = 'e';
	len = ft_hexo_len((unsigned long long)num);
	i = 0;
	s = malloc(sizeof(int) * len);
	len += ft_check_hexo_flag(format, flag);
	while (num != 0)
	{
		s[i++] = num % 16;
		num /= 16;
	}
	i--;
	ft_controlla(format, d, s, i);
	return (len);
}

int	ft_print_hexo(unsigned int num, const char format, char flag)
{
	int	len;

	if (num == 0)
		return (write(1, "0", 1));
	else
	{
		len = ft_put_hexo(num, format, flag);
	}
	return (len);
}
