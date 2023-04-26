#include "main.h"

/**
 * fetch_flags - Calculates active flags
 * @format: string format to print the arguments
 * @i: takes a parameter
 * Return: flags
 */

int fetch_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int f, flags_loop;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (flags_loop = *i + 1; format[flags_loop] != '\0'; flags_loop++)
	{
		for (f = 0; FLAGS_CH[f] != '\0'; f++)
			if (format[flags_loop] == FLAGS_CH[f])
			{
				flags |= FLAGS_ARR[f];
				break;
			}

		if (FLAGS_CH[f] == 0)
			break;
	}

	*i = flags_loop - 1;

	return (flags);
}
