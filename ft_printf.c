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

void	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		i;
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

int main(void)
{
	// ft_putstr_fd("" this is a backslash \\\"\n", 1);
	// printf("%#10d\n", 10);
	/*
	char	*s = "string";
	char	c = 'A';
	int		d = 42;
	ft_printf("sdc", s, d, c);
	*/
	put_nums(5, 34, 5, 65, 89, 42);
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

