/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:41:01 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:24:34 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_format	ft_init_format(void)
{
	t_format	fmt;

	fmt.conversion = '\0';
	fmt.minus = 0;
	fmt.zero = 0;
	fmt.dot = 0;
	fmt.hash = 0;
	fmt.plus = 0;
	fmt.space = 0;
	fmt.width = 0;
	fmt.precision = -1;
	return (fmt);
}

static void	ft_parse_flags_loop(const char **format, t_format *fmt)
{
	while (**format)
	{
		if (**format == '-')
			fmt->minus = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '#')
			fmt->hash = 1;
		else if (**format == '+')
			fmt->plus = 1;
		else if (**format == ' ')
			fmt->space = 1;
		else
			break ;
		(*format)++;
	}
}

static void	ft_parse_width(const char **format, t_format *fmt)
{
	fmt->width = 0;
	while (**format >= '0' && **format <= '9')
	{
		fmt->width = fmt->width * 10 + (**format - '0');
		(*format)++;
	}
}

static void	ft_parse_precision(const char **format, t_format *fmt)
{
	if (**format == '.')
	{
		fmt->dot = 1;
		(*format)++;
		fmt->precision = 0;
		while (**format >= '0' && **format <= '9')
		{
			fmt->precision = fmt->precision * 10 + (**format - '0');
			(*format)++;
		}
	}
}

t_format	ft_parse_format(const char **format)
{
	t_format	fmt;

	fmt = ft_init_format();
	ft_parse_flags_loop(format, &fmt);
	ft_parse_width(format, &fmt);
	ft_parse_precision(format, &fmt);
	if (**format)
		fmt.conversion = **format;
	return (fmt);
}
