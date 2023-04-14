#include "main.h"

/**
 * fetch_flags - Evaluates the active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, cur_x;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_x = *i + 1; format[cur_x] != '\0'; cur_x++)
	{
		for (y = 0; FLAGS_CH[y] != '\0'; y++)
			if (format[cur_x] == FLAGS_CH[y])
			{
				flags |= FLAGS_ARR[y];
				break;
			}

		if (FLAGS_CH[y] == 0)
			break;
	}

	*i = cur_y - 1;

	return (flags);
}
