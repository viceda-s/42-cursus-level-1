/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:50:24 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:23:01 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_calc_uint_zeros(unsigned int num, int digits, t_format *fmt)
{
	int	zeros;

	(void)num;
	if (fmt->dot && fmt->precision > digits)
		zeros = fmt->precision - digits;
	else if (!fmt->dot && fmt->zero && !fmt->minus && fmt->width > digits)
		zeros = fmt->width - digits;
	else
		zeros = 0;
	return (zeros);
}

static int	ft_calc_uint_total(int zeros, int digits, t_format *fmt)
{
	int	total_len;

	if (zeros > 0 && !fmt->zero)
		total_len = fmt->precision;
	else
		total_len = digits;
	if (fmt->zero && fmt->width > digits)
		total_len = fmt->width;
	return (total_len);
}

int	ft_print_formatted_unsigned(unsigned int num, t_format *fmt)
{
	int	count;
	int	zeros;
	int	digits;
	int	total_len;

	count = 0;
	digits = ft_count_digits(num);
	if (fmt->dot && fmt->precision == 0 && num == 0)
	{
		if (fmt->width > 0)
			ft_put_padding_spaces(&count, fmt->width);
		return (count);
	}
	zeros = ft_calc_uint_zeros(num, digits, fmt);
	total_len = ft_calc_uint_total(zeros, digits, fmt);
	if (!fmt->minus && fmt->width > total_len && !fmt->zero)
		ft_put_padding_spaces(&count, fmt->width - total_len);
	ft_put_padding_zeros(&count, zeros);
	count += ft_print_unsigned(num);
	if (fmt->minus && fmt->width > total_len)
		ft_put_padding_spaces(&count, fmt->width - total_len);
	return (count);
}
