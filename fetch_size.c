#include "main.h"

/**
 * fetch_size - Calculates size to cast argument
 * @format: string format in which to print the arguments
 * @i: List of arguments to be printed
 * Return: size
 */

int fetch_size(const char *format, int *i)
{
	int size = 0;
	int size_n = *i + 1;

	if (format[size_n] == 'l')
		size = S_LONG;
	else if (format[size_n] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = size_n - 1;
	else
		*i = size_n;

	return (size);
}
