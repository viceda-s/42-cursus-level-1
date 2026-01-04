/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:50:24 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:23:01 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_put_padding_spaces(int *count, int spaces)
{
	while (spaces-- > 0)
	{
		write(1, " ", 1);
		(*count)++;
	}
}

void	ft_put_padding_zeros(int *count, int zeros)
{
	while (zeros-- > 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
}

int	ft_count_digits(long num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

int	ft_count_hex_digits(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		count++;
		num /= 16;
	}
	return (count);
}

int	ft_handle_zero_precision(int num, t_format *fmt)
{
	int	count;

	(void)num;
	count = 0;
	if (fmt->plus)
	{
		if (!fmt->minus && fmt->width > 1)
			ft_put_padding_spaces(&count, fmt->width - 1);
		count += ft_print_char('+');
		if (fmt->minus && fmt->width > 1)
			ft_put_padding_spaces(&count, fmt->width - 1);
	}
	else if (fmt->space)
	{
		if (!fmt->minus && fmt->width > 1)
			ft_put_padding_spaces(&count, fmt->width - 1);
		count += ft_print_char(' ');
		if (fmt->minus && fmt->width > 1)
			ft_put_padding_spaces(&count, fmt->width - 1);
	}
	else if (fmt->width > 0)
		ft_put_padding_spaces(&count, fmt->width);
	return (count);
}
