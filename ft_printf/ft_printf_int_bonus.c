/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:50:24 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:23:01 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_apply_sign(int num, t_format *fmt, int *count)
{
	if (num < 0)
	{
		write(1, "-", 1);
		(*count)++;
	}
	else if (fmt->plus)
	{
		write(1, "+", 1);
		(*count)++;
	}
	else if (fmt->space)
	{
		write(1, " ", 1);
		(*count)++;
	}
}

static int	ft_calculate_zeros(int num, t_format *fmt)
{
	int	zeros;
	int	digits;

	digits = ft_count_digits(num);
	if (fmt->dot && fmt->precision > digits)
		zeros = fmt->precision - digits;
	else if (fmt->dot)
		zeros = 0;
	else if (num < 0)
		zeros = fmt->width - digits - 1;
	else
		zeros = fmt->width - digits;
	if (!fmt->dot && num >= 0 && (fmt->plus || fmt->space))
		zeros--;
	if (zeros < 0)
		zeros = 0;
	return (zeros);
}

static void	ft_apply_dot_padding(int num, int zeros, t_format *fmt, int *c)
{
	int	total_width;

	total_width = zeros + ft_count_digits(num);
	if (num < 0 || fmt->plus || fmt->space)
		total_width++;
	if (!fmt->minus && fmt->width > total_width)
		ft_put_padding_spaces(c, fmt->width - total_width);
	ft_apply_sign(num, fmt, c);
	ft_put_padding_zeros(c, zeros);
}

static void	ft_apply_prefix_padding(int num, int zeros, t_format *fmt, int *c)
{
	if (fmt->dot && fmt->precision == 0 && num == 0)
		return ;
	if (fmt->dot)
		ft_apply_dot_padding(num, zeros, fmt, c);
	else if (!fmt->minus && fmt->zero && (fmt->plus || fmt->space || num < 0))
	{
		ft_apply_sign(num, fmt, c);
		ft_put_padding_zeros(c, zeros);
	}
	else if (!fmt->minus && fmt->zero)
		ft_put_padding_zeros(c, zeros);
	else if (!fmt->minus && !fmt->zero)
	{
		ft_put_padding_spaces(c, zeros);
		ft_apply_sign(num, fmt, c);
	}
	else if (fmt->minus)
		ft_apply_sign(num, fmt, c);
}

int	ft_print_formatted_num(int num, t_format *fmt)
{
	int		count;
	int		zeros;
	long	n;

	count = 0;
	n = (long)num;
	if (fmt->dot && fmt->precision == 0 && num == 0)
		return (ft_handle_zero_precision(num, fmt));
	zeros = ft_calculate_zeros(num, fmt);
	ft_apply_prefix_padding(num, zeros, fmt, &count);
	if (n < 0)
		count += ft_print_unsigned(-n);
	else
		count += ft_print_unsigned(n);
	if (fmt->minus && fmt->width > count)
		ft_put_padding_spaces(&count, fmt->width - count);
	return (count);
}
