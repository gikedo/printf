#include "main.h"

/**
 * fetch_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int cur_x;
	int width = 0;

	for (cur_x = *i + 1; format[cur_x] != '\0'; cur_x++)
	{
		if (is_digit(format[curr_x]))
		{
			width *= 10;
			width += format[cur_x] - '0';
		}
		else if (format[cur_x] == '*')
		{
			cur_x++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur_x - 1;

	return (width);
}
