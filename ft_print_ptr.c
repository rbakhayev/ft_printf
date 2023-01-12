/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:53:27 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/01 10:59:53 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_controlla(long long unsigned num, char *str)
{
	int		i;
	char	d;

	i = 0;
	while (num != 0)
	{
		str[i++] = num % 16;
		num /= 16;
	}
	i--;
	while (i >= 0)
	{
		if (str[i] >= 0 && str[i] <= 9)
		{
			d = str[i] + '0';
			write(1, &d, 1);
		}
		else if (str[i] >= 10 && str[i] <= 15)
		{
			d = str[i] + 87;
			write(1, &d, 1);
		}
		i--;
	}
	free(str);
}

int	ft_hexo_len(long long unsigned num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

int	ft_print_ptr(long long unsigned num)
{
	int		len;
	char	*str;

	len = ft_hexo_len(num);
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	len += 2;
	str = malloc(sizeof(char *) * len);
	ft_controlla(num, str);
	return (len);
}
