/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:41:01 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 09:24:34 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_handle_conversion(char conversion, t_format *fmt, va_list ap)
{
	if (conversion == 'c')
		return (ft_print_formatted_char(va_arg(ap, int), fmt));
	else if (conversion == 's')
		return (ft_print_formatted_str(va_arg(ap, char *), fmt));
	else if (conversion == 'p')
		return (ft_print_formatted_pointer(va_arg(ap, void *), fmt));
	else if (conversion == 'd' || conversion == 'i')
		return (ft_print_formatted_num(va_arg(ap, int), fmt));
	else if (conversion == 'u')
		return (ft_print_formatted_unsigned(va_arg(ap, unsigned int), fmt));
	else if (conversion == 'x')
		return (ft_print_formatted_hex(va_arg(ap, unsigned int), 0, fmt));
	else if (conversion == 'X')
		return (ft_print_formatted_hex(va_arg(ap, unsigned int), 1, fmt));
	else if (conversion == '%')
		return (ft_print_percent());
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	t_format	fmt;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			fmt = ft_parse_format(&format);
			len += ft_handle_conversion(fmt.conversion, &fmt, ap);
			format++;
		}
		else
		{
			len += ft_print_char(*format);
			format++;
		}
	}
	va_end(ap);
	return (len);
}
