/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:12:04 by timanish          #+#    #+#             */
/*   Updated: 2024/10/07 14:15:33 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	p_ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

int	ap_format(va_list ap, char specifier)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0x";
	if (specifier == 'c')
		count += ft_putchar_fd_p (va_arg(ap, int), 1);
	else if (specifier == 's')
		count += ft_putstr_fd_p (va_arg(ap, char *), 1);
	else if (specifier == 'p')
	{
		write (1, hex, 2);
		count += put_adr(va_arg(ap, unsigned long long), 1);
	}
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_fd_p (va_arg(ap, int), 1);
	else if (specifier == 'u')
		count += ft_putnbr_fd_p (va_arg(ap, unsigned int), 1);
	else if (specifier == 'x' || specifier == 'X')
		count += put_hex (va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count += ft_putchar_fd_p ('%', 1);
	return (count);
}

int	space_word(char word)
{
	int	fd;

	fd = 1;
	if (word == '\a')
		ft_putchar_fd_p('\a', fd);
	if (word == '\b')
		ft_putchar_fd_p('\b', fd);
	if (word == '\t')
		ft_putchar_fd_p('\t', fd);
	if (word == '\n')
		ft_putchar_fd_p('\n', fd);
	if (word == '\v')
		ft_putchar_fd_p('\v', fd);
	if (word == '\f')
		ft_putchar_fd_p('\f', fd);
	if (word == '\r')
		ft_putchar_fd_p('\r', fd);
	if (word == ' ')
		ft_putchar_fd_p(' ', fd);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count += ap_format (ap, *(++format));
		else if (*format >= 7 && *format <= 13)
			count += space_word (*format);
		else
		{
			ft_putchar_fd_p (*format, 1);
			count ++;
		}
		format ++;
	}
	return (count);
}
