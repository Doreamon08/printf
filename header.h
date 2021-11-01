/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:58:45 by rabbie            #+#    #+#             */
/*   Updated: 2021/10/31 14:12:03 by rabbie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //delete

int		ft_putchar(char c);
int		ft_putstr(char *s);
void	ft_putnbr(long num);
int		to_heximal(int i, char x);
size_t	ft_strlen(const char *c);
int		numlen(long l);

#endif