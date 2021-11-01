/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:02:03 by rabbie            #+#    #+#             */
/*   Updated: 2021/11/01 15:23:48 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
		i += ft_putchar(*s++);
	return (i);
}

void	ft_putnbr(long num)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = num * -1;
	}
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar((num % 10) + '0');
}

int	to_heximal(unsigned long long i, char x)
{
	int	ost;
	int	q;

	ost = 0;
	q = 0;
	if (i > 16)
		q = to_heximal(i / 16, x);
	ost = i % 16;
	i /= 16;
	if (ost >= 10)
	{
		if (x == 'X')
			q += ft_putchar((ost - 10) + 'A');
		if (x == 'x')
			q += ft_putchar((ost - 10) + 'a');
	}
	else
	{
		ft_putnbr(ost);
		q++;
	}
	return (q);
}
