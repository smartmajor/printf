#include "main.h"

/**
 * fetch_width - function calculates the width for printing
 * @format: string format in which to print the arguments.
 * @i: List of arguments to be printed
 * @list: list of arguments
 * Return: width
 */
int fetch_width(const char *format, int *i, va_list list)
{
	int width_loop;
	int width = 0;

	for (width_loop = *i + 1; format[width_loop] != '\0'; width_loop++)
	{
		if (is_digit(format[width_loop]))
		{
			width = width * 10;
			width = width + format[width_loop] - '0';
		}
		else if (format[width_loop] == '*')
		{
			width_loop++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = width_loop - 1;

	return (width);
}
