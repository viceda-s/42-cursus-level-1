/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:30:38 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/25 19:39:38 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_print_formatted_pointer(void *ptr, t_format *fmt)
{
	int				count;
	unsigned long	addr;
	int				len;

	if (!ptr)
		return (ft_print_formatted_str("(nil)", fmt));
	count = 0;
	addr = (unsigned long)ptr;
	len = 2;
	if (addr == 0)
		len += 1;
	else
	{
		while (addr > 0)
		{
			len++;
			addr /= 16;
		}
	}
	if (!fmt->minus && fmt->width > len)
		ft_put_padding_spaces(&count, fmt->width - len);
	count += ft_print_pointer(ptr);
	if (fmt->minus && fmt->width > len)
		ft_put_padding_spaces(&count, fmt->width - len);
	return (count);
}
