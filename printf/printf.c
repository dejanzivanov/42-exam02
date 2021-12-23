#include <unistd.h>
#include <stdarg.h>


int ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}
int ft_putstr(char *str)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	if(!str)
	{
		str = "(null)";
	}
	while(str[i])
	{
		counter += ft_putchar(str[i]);
		i++;
	}
	return counter;
}

int ft_putnbr(int i, int base)
{
	int counter;
	int remainder;
	char *arr = "0123456789abcdef";

	counter = 0;
	remainder = 0;
	if(i / base != 0)
	{
		counter += ft_putnbr(i / base, base);
	}
	remainder = i % base;
	counter += write(1, &arr[remainder], 1);
	return (counter);
}

int ft_int(int i)
{
	int counter;
	counter = 0;
	if(i == -2147483648)
	{
		write(1, "-2147483648", 12);
		counter = 12;
		return counter;
	}
	if(i < 0)
	{
		i = i * -1;
		counter += ft_putchar('-');
	}
	counter += ft_putnbr(i, 10);
	return (counter);
}

int ft_printf(const char *format, ...)
{
	int counter;
	int index;

	if (!format)
	{
		return 0;
	}
	va_list args;

	counter = 0;
	index = 0;
	va_start(args, format);
	while(format[index])
	{
		if(format[index] == '%')
		{
			index++;
			if(format[index] == 's')
			{
				counter += ft_putstr(va_arg(args, char *));
			}
			if(format[index] == 'd')
			{
				counter += ft_int(va_arg(args, int));
			}
			if(format[index] == 'x')
			{
				counter += ft_putnbr(va_arg(args, unsigned int), 16);
			}
		}
		else
		{
			counter += ft_putchar(format[index]);
		}
		index++;
	}
	va_end(args);
	return (counter);
}
