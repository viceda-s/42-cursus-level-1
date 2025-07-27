/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viceda-s <viceda-s@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:11:27 by viceda-s          #+#    #+#             */
/*   Updated: 2025/06/26 07:14:28 by viceda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_percent(void);

int	ft_print_num(int num);
int	ft_print_unsigned(unsigned int num);
int	ft_print_hex(unsigned int num, int uppercase);
int	ft_print_pointer(void *ptr);

int	ft_printf(const char *format, ...);

#endif
