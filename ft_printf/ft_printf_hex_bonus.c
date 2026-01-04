/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:50:24 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:23:01 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_print_hex_recursive(unsigned int num, int uppercase)
{
	int		len;
	char	*hex;

	len = 0;
	if (uppercase)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (num >= 16)
		len += ft_print_hex_recursive(num / 16, uppercase);
	len += ft_print_char(hex[num % 16]);
	return (len);
}

static int	ft_apply_hex_prefix(unsigned int num, int uppercase, int *count)
{
	if (num != 0)
	{
		if (uppercase)
			*count += ft_print_str("0X");
		else
			*count += ft_print_str("0x");
		return (2);
	}
	return (0);
}

static int	ft_calc_hex_zeros(unsigned int num, int hex_digits, t_format *fmt)
{
	int	prec_zeros;

	if (fmt->dot && fmt->precision > hex_digits)
		prec_zeros = fmt->precision - hex_digits;
	else if (!fmt->dot && fmt->zero && !fmt->minus && fmt->width > hex_digits)
	{
		prec_zeros = fmt->width - hex_digits;
		if (fmt->hash && num != 0)
			prec_zeros -= 2;
	}
	else
		prec_zeros = 0;
	return (prec_zeros);
}

static int	ft_calc_hex_total(int prec_zeros, int hex_digits, t_format *fmt,
		unsigned int num)
{
	int	total_len;

	if (prec_zeros > 0 && !fmt->zero)
		total_len = fmt->precision;
	else
		total_len = hex_digits;
	if (fmt->zero && fmt->width > hex_digits)
		total_len = fmt->width;
	if (fmt->hash && num != 0)
		total_len += 2;
	return (total_len);
}

int	ft_print_formatted_hex(unsigned int num, int uppercase, t_format *fmt)
{
	int	count;
	int	prec_zeros;
	int	hex_digits;
	int	total_len;

	count = 0;
	hex_digits = ft_count_hex_digits(num);
	if (fmt->dot && fmt->precision == 0 && num == 0)
	{
		if (fmt->width > 0)
			ft_put_padding_spaces(&count, fmt->width);
		return (count);
	}
	prec_zeros = ft_calc_hex_zeros(num, hex_digits, fmt);
	total_len = ft_calc_hex_total(prec_zeros, hex_digits, fmt, num);
	if (!fmt->minus && fmt->width > total_len && !fmt->zero)
		ft_put_padding_spaces(&count, fmt->width - total_len);
	if (fmt->hash && num != 0)
		ft_apply_hex_prefix(num, uppercase, &count);
	ft_put_padding_zeros(&count, prec_zeros);
	count += ft_print_hex_recursive(num, uppercase);
	if (fmt->minus && fmt->width > total_len)
		ft_put_padding_spaces(&count, fmt->width - total_len);
	return (count);
}
