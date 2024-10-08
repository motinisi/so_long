/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:20:49 by timanish          #+#    #+#             */
/*   Updated: 2024/10/07 14:16:16 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_p(char c, int fd)
{
	int	count;

	count = 1;
	write (fd, &c, sizeof(char));
	return (count);
}

int	ft_putnbr_fd_p(long long n, int fd)
{
	long long	nbr;
	int			count;

	count = 0;
	nbr = n;
	if (!nbr)
		count += 1;
	if (nbr < 0)
	{
		ft_putchar_fd_p('-', fd);
		nbr = nbr * -1;
		count += 1;
	}
	if (nbr > 9)
		ft_putnbr_fd_p (nbr / 10, fd);
	ft_putchar_fd_p (nbr % 10 + '0', fd);
	while (n)
	{
		n /= 10;
		count += 1;
	}
	return (count);
}

int	ft_putstr_fd_p(char *s, int fd)
{
	if (s == NULL)
		s = "(null)";
	write (fd, s, p_ft_strlen(s));
	return (p_ft_strlen(s));
}

int	put_hex(unsigned int ap, char specifier)
{
	unsigned int	hex;
	int				fd;
	int				count;

	fd = 1;
	hex = ap;
	count = 0;
	if (hex >= 16)
		put_hex(hex / 16, specifier);
	if (specifier == 'x')
		ft_putchar_fd_p("0123456789abcdef"[hex % 16], fd);
	if (specifier == 'X')
		ft_putchar_fd_p("0123456789ABCDEF"[hex % 16], fd);
	if (!ap)
		count += 1;
	while (ap)
	{
		ap /= 16;
		count ++;
	}
	return (count);
}

int	put_adr(unsigned long long ap, int fd)
{
	unsigned long long	adr;
	int					count;

	adr = ap;
	count = 2;
	if (adr >= 16)
		put_adr(adr / 16, 1);
	if (adr < 10)
		ft_putchar_fd_p (adr + '0', fd);
	else if (adr >= 10)
		ft_putchar_fd_p("0123456789abcdef"[adr % 16], fd);
	if (!ap)
		return (count + 1);
	while (ap)
	{
		ap /= 16;
		count ++;
	}
	return (count);
}
