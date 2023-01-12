/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:44:03 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/01 10:49:32 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

int	ft_print_str(char *st)
{
	int	len;

	len = 0;
	if (!st)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*st)
	{
		write(1, st, 1);
		st++;
		len++;
	}
	return (len);
}

int	ft_print_num(int num, char flag)
{
	int		len;
	char	*n;

	len = 0;
	if (flag == ' ' && num >= 0)
	{
		write(1, " ", 1);
		len += 1;
	}
	else if (flag == '+' && num >= 0)
	{
		write(1, "+", 1);
		len += 1;
	}
	n = ft_itoa(num);
	len += ft_print_str(n);
	free(n);
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
