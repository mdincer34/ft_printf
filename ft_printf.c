/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudincer <mudincer@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:19:04 by mudincer          #+#    #+#             */
/*   Updated: 2023/10/28 14:45:40 by mudincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_check_format(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_hex(va_arg(args, unsigned int), "0123456789abcdef", 0));
	else if (c == 'X')
		return (ft_hex(va_arg(args, unsigned int), "0123456789ABCDEF", 0));
	else if (c == 'p')
		return (ft_hex(va_arg(args, unsigned long int), "0123456789abcdef", 1));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_logic(va_list args, const char *format)
{
	int		i;
	int		check;

	i = 0;
	while (*format)
	{
		if (*format == '%' )
		{
			format++;
			check = ft_check_format(args, *format);
			if (check == -1)
				return (-1);
			i += check;
		}
		else if (*format != '%')
		{
			if (ft_putchar(*format) == -1)
				return (-1);
			i++;
		}
		format++;
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = ft_logic(args, format);
	va_end(args);
	return (i);
}
