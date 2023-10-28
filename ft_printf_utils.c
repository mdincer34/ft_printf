/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudincer <mudincer@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:28:47 by mudincer          #+#    #+#             */
/*   Updated: 2023/10/28 14:41:14 by mudincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *ptr)
{
	int	i;

	if (!ptr)
	{
		if (ft_putstr("(null)") == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (ptr[i])
	{
		if (ft_putchar(ptr[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;
	int	value;

	i = 0;
	if (n == 0)
		return (ft_putstr("0"));
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		value = ft_putnbr(n / 10);
		if (value == -1)
			return (-1);
		i += value;
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (i + 1);
}

int	ft_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (ft_putstr("0"));
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		if (i == -1)
			return (-1);
	}
	if (ft_putchar("0123456789"[n % 10]) == -1)
		return (-1);
	return (i + 1);
}

int	ft_hex(unsigned long int n, char *hex, int mode)
{
	int	i;
	int	value;

	i = 0;
	if (mode)
	{
		if (ft_putstr("0x") == -1)
			return (-1);
		i += 2;
		mode = 0;
	}
	if (n >= 16)
	{
		value = ft_hex(n / 16, hex, mode);
		if (value == -1)
			return (-1);
		i += value;
	}
	if (ft_putchar(hex[n % 16]) == -1)
		return (-1);
	return (i + 1);
}
