/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:07:35 by rabbie            #+#    #+#             */
/*   Updated: 2021/11/05 15:11:19 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fornumbers(va_list ap, char c)
{
	int		i;
	long	num;

	i = 0;
	if (c == 'u')
	{
		num = va_arg(ap, unsigned int);
		ft_putnbr(num);
		i += numlen(num);
	}
	else
	{
		num = va_arg(ap, int);
		ft_putnbr(num);
		i += numlen(num);
	}
	return (i);
}

int	numlen(long l)
{
	int	i;

	i = 0;
	if (l <= 0)
	{
		i++;
		l *= -1;
	}
	while (l > 0)
	{
		l /= 10;
		i++;
	}
	return (i);
}

int	printer(const char *str, va_list ap)
{
	int		i;
	char	*s;

	i = 0;
	if (*str == '%')
		i += ft_putchar('%');
	if (*str == 's')
	{
		s = va_arg(ap, char *);
		i += ft_putstr(s);
	}
	if (*str == 'd' || *str == 'i')
		i += fornumbers(ap, *str);
	if (*str == 'c')
		i += ft_putchar((char)va_arg(ap, int));
	if (*str == 'p')
	{
		i += ft_putstr("0x");
		i += to_heximal(va_arg(ap, unsigned long long), 'x');
	}
	if (*str == 'u')
		i += fornumbers(ap, *str);
	if (*str == 'X' || *str == 'x')
		i += to_heximal(va_arg(ap, unsigned int), *str);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			(void)*str++;
			i += printer(str, ap);
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		(void)*str++;
	}
	va_end(ap);
	return (i);
}

// int main()
// {
// 	int a = -2;
// 	int *p = &a;
// 	int		ft_p;
// 	int		pr;

// 	// ft_p = ft_printf("%s - string\n%d - number(d)\n%c - char\n%u - unsigned int\n%x - HEX\n%%\n%p - ponter\n",
// 	//  "begin", 6, 'c', 4294967295, 323947, p);
// 	// printf("------------------------\n");
// 	// pr = printf("%s - string\n%d - number(d)\n%c - char\n%u - unsigned int\n%x - HEX\n%%\n%p - ponter\n",
// 	//  "begin", 6, 'c', 429496, 323947, p);
// 	ft_p = ft_printf(" %x ", a);
// 	printf("\n------------------------\n");
// 	pr = printf(" %x ", a);
// 	printf("\n%d - ft_p, %d - pr\n", ft_p, pr);
// }