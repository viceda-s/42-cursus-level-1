/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:41:01 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:24:34 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_formatted_char(char c, t_format *fmt)
{
	int	count;

	count = 0;
	if (fmt->minus)
	{
		count += ft_print_char(c);
		while (count < fmt->width)
		{
			write(1, " ", 1);
			count++;
		}
	}
	else
	{
		while (count < fmt->width - 1)
		{
			write(1, " ", 1);
			count++;
		}
		count += ft_print_char(c);
	}
	return (count);
}

static void	ft_print_str_content(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

static int	ft_handle_str_left_align(char *str, int str_len, t_format *fmt)
{
	int	count;

	count = 0;
	ft_print_str_content(str, str_len);
	count = str_len;
	while (count < fmt->width)
	{
		write(1, " ", 1);
		count++;
	}
	return (count);
}

static int	ft_handle_str_right_align(char *str, int str_len, t_format *fmt)
{
	int	count;

	count = 0;
	while (count < fmt->width - str_len)
	{
		write(1, " ", 1);
		count++;
	}
	ft_print_str_content(str, str_len);
	count += str_len;
	return (count);
}

int	ft_print_formatted_str(char *str, t_format *fmt)
{
	int	str_len;
	int	was_null;

	was_null = 0;
	if (!str)
	{
		str = "(null)";
		was_null = 1;
	}
	str_len = ft_strlen(str);
	if (fmt->dot && fmt->precision < str_len)
	{
		str_len = fmt->precision;
		if (was_null && fmt->precision < 6)
			str_len = 0;
	}
	if (fmt->minus)
		return (ft_handle_str_left_align(str, str_len, fmt));
	else
		return (ft_handle_str_right_align(str, str_len, fmt));
}
