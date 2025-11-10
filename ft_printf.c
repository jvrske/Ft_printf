/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva <csilva@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:53:12 by csilva            #+#    #+#             */
/*   Updated: 2025/11/10 18:14:42 by csilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

static int	ft_conversion(const char format, va_list args, int scount)
{
	if (format == 'c')
		scount += ft_putchar_fd(va_arg(args, int), 1);
	else if (format == 's')
		scount += ft_putstr_fd(va_arg(args, char *), 1);
	else if (format == 'p')
		scount += ft_checkaddres(va_arg(args, void *), scount);
	else if (format == 'd' || format == 'i')
		scount += ft_putnbr_fd(va_arg(args, int), 1, scount);
	else if (format == 'u')
		scount += ft_putnbr_base(va_arg(args, unsigned int), "0123456789",
				scount);
	else if (format == 'x')
		scount += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef",
				scount);
	else if (format == 'X')
		scount += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF",
				scount);
	else if (format == '%')
		scount += ft_putchar_fd('%', 1);
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
			count += ft_conversion(format[i + 1], args, 0);
			if (count <= -1)
				return (-1);
			i += 2;
		}
		else
			count += ft_putchar_fd(format[i++], 1);
	}
	va_end(args);
	return (count);
}

/* int	main(void)
{
	printf("\n%d\n", ft_printf("Meu nome e %c", 'c'));
	printf("\n%d\n", printf("Meu nome e %c", 'c'));

	printf("\n%d\n", ft_printf("Meu nome e %s", "Caio"));
	printf("\n%d\n", printf("Meu nome e %s", "Caio"));

	printf("\n%d\n", ft_printf("Meu nome e %p", "Caio"));
	printf("\n%d\n", printf("Meu nome e %p", "Caio"));

	printf("\n%d\n", ft_printf("%d", 12345));
	printf("\n%d\n", printf("%d", 12345));

	printf("\n%d\n", ft_printf("%i", 1995));
	printf("\n%d\n", printf("%i", 1995));

	printf("\n%d\n", ft_printf("%u", 199));
	printf("\n%d\n", printf("%u", 199));

	printf("\n%d\n", ft_printf("%x", -2147483647));
	printf("\n%d\n", printf("%x", -2147483647));

	printf("\n%d\n", ft_printf("%X", -2147483647));
	printf("\n%d\n", printf("%X", -2147483647));

	printf("\n%d\n", ft_printf("%%"));
	printf("\n%d\n", printf("%%"));
} */

/* #include <limits.h>
#include <stdio.h>

void	test_char(void)
{
	int ft, or ;
	printf("\n========== %%c (CHARACTER) TESTS ==========\n");
	printf("\n[Test 1] Regular character:\n");
	ft = ft_printf("ft: '%c'\n", 'A');
	or = printf("or: '%c'\n", 'A');
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Digit character:\n");
	ft = ft_printf("ft: '%c'\n", '5');
	or = printf("or: '%c'\n", '5');
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] Space character:\n");
	ft = ft_printf("ft: '%c'\n", ' ');
	or = printf("or: '%c'\n", ' ');
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] Null character (\\0):\n");
	ft = ft_printf("ft: '%c%c%c'\n", 'A', '\0', 'B');
	or = printf("or: '%c%c%c'\n", 'A', '\0', 'B');
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] Special characters:\n");
	ft = ft_printf("ft: '%c' '%c' '%c'\n", '\n', '\t', '\\');
	or = printf("or: '%c' '%c' '%c'\n", '\n', '\t', '\\');
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 6] Multiple chars:\n");
	ft = ft_printf("ft: %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e');
	or = printf("or: %c %c %c %c %c\n", 'a', 'b', 'c', 'd', 'e');
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_string(void)
{
	int ft, or ;
	printf("\n========== %%s (STRING) TESTS ==========\n");
	printf("\n[Test 1] Regular string:\n");
	ft = ft_printf("ft: '%s'\n", "Hello World");
	or = printf("or: '%s'\n", "Hello World");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Empty string:\n");
	ft = ft_printf("ft: '%s'\n", "");
	or = printf("or: '%s'\n", "");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] NULL string:\n");
	ft = ft_printf("ft: '%s'\n", NULL);
	or = printf("or: '%s'\n", "(null)");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] String with special chars:\n");
	ft = ft_printf("ft: '%s'\n", "Hello\nWorld\ttab");
	or = printf("or: '%s'\n", "Hello\nWorld\ttab");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] Long string:\n");
	ft = ft_printf("ft: '%s'\n",
			"This is a very long string for testing purposes");
	or = printf("or: '%s'\n",
			"This is a very long string for testing purposes");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 6] Multiple strings:\n");
	ft = ft_printf("ft: %s %s %s\n", "one", "two", "three");
	or = printf("or: %s %s %s\n", "one", "two", "three");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_pointer(void)
{
	int		x;
	char		*str;

	int ft, or ;
	x = 42;
	str = "test";
	printf("\n========== %%p (POINTER) TESTS ==========\n");
	printf("\n[Test 1] Valid pointer:\n");
	ft = ft_printf("ft: %p\n", &x);
	or = printf("or: %p\n", &x);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] NULL pointer:\n");
	ft = ft_printf("ft: %p\n", NULL);
	or = printf("or: %p\n", NULL);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] String pointer:\n");
	ft = ft_printf("ft: %p\n", str);
	or = printf("or: %p\n", str);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] Multiple pointers:\n");
	ft = ft_printf("ft: %p %p %p\n", &x, str, NULL);
	or = printf("or: %p %p %p\n", &x, str, NULL);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] Pointer address range:\n");
	ft = ft_printf("ft: %p\n", (void *)0xFFFFFFFF);
	or = printf("or: %p\n", (void *)0xFFFFFFFF);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_integer(void)
{
	int ft, or ;
	printf("\n========== %%d / %%i (INTEGER) TESTS ==========\n");
	printf("\n[Test 1] Positive number:\n");
	ft = ft_printf("ft: %d %i\n", 42, 42);
	or = printf("or: %d %i\n", 42, 42);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Negative number:\n");
	ft = ft_printf("ft: %d %i\n", -42, -42);
	or = printf("or: %d %i\n", -42, -42);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] Zero:\n");
	ft = ft_printf("ft: %d %i\n", 0, 0);
	or = printf("or: %d %i\n", 0, 0);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] INT_MAX:\n");
	ft = ft_printf("ft: %d\n", INT_MAX);
	or = printf("or: %d\n", INT_MAX);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] INT_MIN:\n");
	ft = ft_printf("ft: %d\n", INT_MIN);
	or = printf("or: %d\n", INT_MIN);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 6] Multiple integers:\n");
	ft = ft_printf("ft: %d %d %d %d %d\n", -100, -1, 0, 1, 100);
	or = printf("or: %d %d %d %d %d\n", -100, -1, 0, 1, 100);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 7] Large numbers:\n");
	ft = ft_printf("ft: %d %d\n", 999999, -999999);
	or = printf("or: %d %d\n", 999999, -999999);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_unsigned(void)
{
	int ft, or ;
	printf("\n========== %%u (UNSIGNED) TESTS ==========\n");
	printf("\n[Test 1] Positive number:\n");
	ft = ft_printf("ft: %u\n", 42);
	or = printf("or: %u\n", 42);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Zero:\n");
	ft = ft_printf("ft: %u\n", 0);
	or = printf("or: %u\n", 0);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] UINT_MAX:\n");
	ft = ft_printf("ft: %u\n", UINT_MAX);
	or = printf("or: %u\n", UINT_MAX);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] Large number:\n");
	ft = ft_printf("ft: %u\n", 4000000000u);
	or = printf("or: %u\n", 4000000000u);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] Multiple unsigned:\n");
	ft = ft_printf("ft: %u %u %u\n", 0, 123, 999999);
	or = printf("or: %u %u %u\n", 0, 123, 999999);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 6] Negative as unsigned (wraps):\n");
	ft = ft_printf("ft: %u\n", -1);
	or = printf("or: %u\n", -1);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_hex(void)
{
	int ft, or ;
	printf("\n========== %%x / %%X (HEXADECIMAL) TESTS ==========\n");
	printf("\n[Test 1] Lowercase hex - small number:\n");
	ft = ft_printf("ft: %x\n", 42);
	or = printf("or: %x\n", 42);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Uppercase hex - small number:\n");
	ft = ft_printf("ft: %X\n", 42);
	or = printf("or: %X\n", 42);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] Lowercase hex - zero:\n");
	ft = ft_printf("ft: %x\n", 0);
	or = printf("or: %x\n", 0);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] Lowercase hex - 255 (ff):\n");
	ft = ft_printf("ft: %x\n", 255);
	or = printf("or: %x\n", 255);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] Uppercase hex - 255 (FF):\n");
	ft = ft_printf("ft: %X\n", 255);
	or = printf("or: %X\n", 255);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 6] Lowercase hex - large number:\n");
	ft = ft_printf("ft: %x\n", 0xDEADBEEF);
	or = printf("or: %x\n", 0xDEADBEEF);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 7] Uppercase hex - large number:\n");
	ft = ft_printf("ft: %X\n", 0xDEADBEEF);
	or = printf("or: %X\n", 0xDEADBEEF);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 8] Mixed case in same call:\n");
	ft = ft_printf("ft: %x %X %x %X\n", 10, 10, 255, 255);
	or = printf("or: %x %X %x %X\n", 10, 10, 255, 255);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 9] UINT_MAX in hex:\n");
	ft = ft_printf("ft: %x\n", UINT_MAX);
	or = printf("or: %x\n", UINT_MAX);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 10] Negative number as hex:\n");
	ft = ft_printf("ft: %x\n", -1);
	or = printf("or: %x\n", -1);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_percent(void)
{
	int ft, or ;
	printf("\n========== %%%% (PERCENT) TESTS ==========\n");
	printf("\n[Test 1] Single percent:\n");
	ft = ft_printf("ft: %%\n");
	or = printf("or: %%\n");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Double percent:\n");
	ft = ft_printf("ft: %%%%\n");
	or = printf("or: %%%%\n");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] Percent with text:\n");
	ft = ft_printf("ft: 100%% complete\n");
	or = printf("or: 100%% complete\n");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] Multiple percents:\n");
	ft = ft_printf("ft: %% %% %% %%\n");
	or = printf("or: %% %% %% %%\n");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

void	test_mixed(void)
{
	int x;

	int ft, or ;
	x = 42;
	printf("\n========== MIXED FORMAT TESTS ==========\n");
	printf("\n[Test 1] All formats together:\n");
	ft = ft_printf("ft: %c %s %p %d %i %u %x %X %%\n", 'A', "test", &x, 42, -42,
							100, 255, 255);
	or = printf("or: %c %s %p %d %i %u %x %X %%\n", 'A', "test", &x, 42, -42,
							100, 255, 255);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 2] Complex string:\n");
	ft = ft_printf("ft: Name: %s, Age: %d, Score: %u, ID: %x\n", "John", 25, 95,
							0xABC);
	or = printf("or: Name: %s, Age: %d, Score: %u, ID: %x\n", "John", 25, 95,
							0xABC);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 3] No formats (plain text):\n");
	ft = ft_printf("ft: Hello World!\n");
	or = printf("or: Hello World!\n");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 4] Empty string:\n");
	ft = ft_printf("\n");
	or = printf("\n");
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
	printf("\n[Test 5] Many of same format:\n");
	ft = ft_printf("ft: %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7,
							8, 9, 10);
	or = printf("or: %d %d %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8,
							9, 10);
	printf("Return: ft=%d, or=%d %s\n", ft, or, ft == or ? "✓" : "✗");
}

int	main(void)
{
	printf("\n╔════════════════════════════════════════════════════╗\n");
	printf("║     FT_PRINTF COMPREHENSIVE TEST SUITE             ║\n");
	printf("╚════════════════════════════════════════════════════╝\n");
	test_char();
	test_string();
	test_pointer();
	test_integer();
	test_unsigned();
	test_hex();
	test_percent();
	test_mixed();
	printf("\n╔════════════════════════════════════════════════════╗\n");
	printf("║     ALL TESTS COMPLETED                            ║\n");
	printf("╚════════════════════════════════════════════════════╝\n");
	return (0);
} */