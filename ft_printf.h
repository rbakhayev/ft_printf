/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbakhaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 10:32:28 by rbakhaye          #+#    #+#             */
/*   Updated: 2022/12/01 10:43:11 by rbakhaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_put_hexo(unsigned int num, const char format, char flag);
int					ft_printf(const char *str, ...);
int					ft_check_type(va_list args, const char *str);
int					ft_print_char(int c);
int					ft_printpercent(void);
int					ft_print_num(int num, char flag);
int					ft_print_str(char *st);
int					ft_num_len(unsigned int num);
int					ft_print_hexo(unsigned int num, const char format,
						char flag);
int					ft_print_ptr(long long unsigned num);
int					ft_hexo_len(long long unsigned num);
int					ft_print_unsigned(unsigned int num);
int					ft_check_hexo_flag(const char format, char flag);

char				ft_check_flag(const char format, const char *str);
char				*ft_uitoa(unsigned int num);

#endif
