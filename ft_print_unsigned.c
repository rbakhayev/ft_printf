/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:50:47 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/01 10:52:51 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int num)
{
	int		len;
	char	*str_num;

	len = ft_num_len(num);
	str_num = malloc(sizeof(char) * len + 1);
	if (!str_num)
		return (NULL);
	str_num[len] = '\0';
	if (num == 0)
		str_num[0] = '0';
	while (num)
	{
		str_num[--len] = (num % 10) + '0';
		num /= 10;
	}	
	return (str_num);
}

int	ft_print_unsigned(unsigned int num)
{
	int		len;
	char	*n;

	len = 0;
	n = ft_uitoa(num);
	len = ft_print_str(n);
	free(n);
	return (len);
}
