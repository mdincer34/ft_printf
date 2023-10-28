/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mudincer <mudincer@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:52:00 by mudincer          #+#    #+#             */
/*   Updated: 2023/10/27 20:10:54 by mudincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(int c);
int	ft_putstr(char *ptr);
int	ft_putnbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_hex(unsigned long int n, char *hex, int mode);
int	ft_printf(const char *format, ...);

#endif
