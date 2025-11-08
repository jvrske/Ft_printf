/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:53:12 by csilva            #+#    #+#             */
/*   Updated: 2025/11/08 17:47:35 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

static int	ft_conversion(const char format, va_list args, int scount)
{	//cspdiuxX%
/* 	if (format == 'c')
		ft_putchar_fd(va_arg(args, char), 1); */
	if (format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else
		return (-1);
	return (scount);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_conversion(format[i + 1], args, count);
			if (count == -1)
				return (-1);
			i += 2;
		}
		ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	char	*c = "abcde";
	ft_printf("Meu nome e %s", c);

}
