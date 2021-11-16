#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void	put_nums(int n, ...)
{
	va_list	ap;
	int		val;
	
	va_start(ap, n);
	while (n--)
	{
		val = va_arg(ap, int);
		printf("%d\n", val);
	}
	va_end(ap);
}

void	ft_format(const char *f, ...)
{
	va_list	ap;
	int		d;
	char	c;
	char	*s;

	va_start(ap, f);
	while (*f)
	{
		if (*f == 's')
		{
			s = va_arg(ap, char *);
			printf("%s\n", s);
		}
		else if (*f == 'd')
		{
			d = va_arg(ap, int);
			printf("%d\n", d);
		}
		else if (*f == 'c')
		{
			c = (char) va_arg(ap, int);
			printf("%c\n", c);
		}
		f++;
	}
	va_end(ap);
}


// you could return the charecters themselves rather than the numbers
int	specifier(char *pt)
{
	if (pt[0] == '%')
	{
		if (pt[1] == 'c')
			return (1);
		if (pt[1] == 's')
			return (2);
	//	if (pt[1] == 'p')
	//		return (3);
		if (pt[1] == 'd')
			return (4);
	}
	return (0);
}

void	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		sp;
	// int		print_last = 0;
	int		i = 0;
	int		d;
	char	c;
	char	*s;
	// void	*p;

	va_start(ap, fmt);
	while (fmt[i])
	{
		if (!fmt[i + 1])
		{
			ft_putchar_fd(fmt[i], 1);
			i++;
			continue ;
		}
		sp = specifier((char *)fmt + i);
		if (sp == 1)
		{
			c = (char)va_arg(ap, int);
			ft_putchar_fd(c, 1);
			i++;
		}
		else if (sp == 2)
		{
			s = va_arg(ap, char *);
			ft_putstr_fd(s, 1);
			i++;
		}
//		else if (sp == 3)
//		{
//			p = va_arg(ap, void *);
//			ft_putnbr_fd((int)p, 1);
//		}
		else if (sp == 4)
		{
			d = va_arg(ap, int);
			ft_putnbr_fd(d, 1);
			i++;
		}
		else
			ft_putchar_fd(fmt[i], 1);
		i++;
	}
	va_end(ap);
}

int main(void)
{
	ft_printf("string:  %s   character: %c   integer:  %d\n", "str1", 'R', 1337);
}


#include <stdio.h>
#include <stdarg.h>

void
foo(char *fmt, ...)   /* '...' is C syntax for a variadic function */

{
    va_list ap;
    int d;
    char c, *s;

    va_start(ap, fmt);
    while (*fmt)
        switch (*fmt++) {
        case 's':              /* string */
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    va_end(ap);
}

