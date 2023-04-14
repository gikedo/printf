#include "main.h"

/**
 * fetch_size - Evaluates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int cur_x = *i + 1;
	int size = 0;

	if (format[cur_x] == 'l')
		size = S_LONG;
	else if (format[cur_x] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur_x - 1;
	else
		*i = cur_x;

	return (size);
}
