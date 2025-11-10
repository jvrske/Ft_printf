/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:09:40 by csilva            #+#    #+#             */
/*   Updated: 2025/11/10 18:12:08 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>

int	ft_putaddres(unsigned long n, int count);
int	ft_checkaddres(void *n, int count);
int	ft_putnbr_base(unsigned int n, char *base, int count);
int	ft_printf(const char *format, ...);

#endif