/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:11:27 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 07:14:28 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_format
{
	char	conversion;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		plus;
	int		space;
	int		width;
	int		precision;
}	t_format;

int			ft_printf(const char *format, ...);
t_format	ft_parse_format(const char **format);
int			ft_print_char(char c);
int			ft_print_str(char *str);
int			ft_print_percent(void);
int			ft_strlen(const char *s);
int			ft_print_num(int num);
int			ft_print_unsigned(unsigned int num);
int			ft_print_hex(unsigned int num, int uppercase);
int			ft_print_hex_ulong(unsigned long num);
int			ft_print_pointer(void *ptr);
int			ft_print_formatted_char(char c, t_format *fmt);
int			ft_print_formatted_str(char *str, t_format *fmt);
int			ft_print_formatted_num(int num, t_format *fmt);
int			ft_print_formatted_unsigned(unsigned int num, t_format *fmt);
int			ft_print_formatted_hex(unsigned int num, int uppercase,
				t_format *fmt);
int			ft_print_formatted_pointer(void *ptr, t_format *fmt);
int			ft_handle_zero_precision(int num, t_format *fmt);
void		ft_put_padding_spaces(int *count, int spaces);
void		ft_put_padding_zeros(int *count, int zeros);
int			ft_count_digits(long num);
int			ft_count_hex_digits(unsigned int num);

#endif
