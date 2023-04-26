#include "main.h"

/**
 * fetch_precision - function calculates the precision for printing
 * @format: string format to print arguments
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: Precision
 */

int fetch_precision(const char *format, int *i, va_list list)
{
	int precision_loop = *i + 1;
	int precision = -1;

	if (format[precision_loop] != '.')
		return (precision);

	precision = 0;

	for (precision_loop += 1; format[precision_loop] != '\0'; precision_loop++)
	{
		if (is_digit(format[precision_loop]))
		{
			precision = precision * 10;
			precision = precision + format[precision_loop] - '0';
		}
		else if (format[precision_loop] == '*')
		{
			precision_loop++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = precision_loop - 1;

	return (precision);
}
