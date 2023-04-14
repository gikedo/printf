#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur_x = *i + 1;
	int precision = -1;

	if (format[cur_x] != '.')
		return (precision);

	precision = 0;

	for (cur_x += 1; format[cur_x] != '\0'; cur_x++)
	{
		if (is_digit(format[cur_x]))
		{
			precision *= 10;
			precision += format[cur_x] - '0';
		}
		else if (format[cur_x] == '*')
		{
			cur_x++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_x - 1;

	return (precision);
}
