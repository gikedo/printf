#include "main.h"

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        unsigned int x, y, z, sum;
        unsigned int r[32];
        int count;

        UNUSED(buffer);
        UNUSED(flags);
        UNUSED(width);
        UNUSED(precision);
        UNUSED(size);

        x = va_arg(types, unsigned int);
        y = 2147483648; /* (2 ^ 31) */
        r[0] = x / y;
        for (z = 1; z < 32; z++)
        {
                y /= 2;
                r[z] = (x / y) % 2;
        }
        for (z = 0, sum = 0, count = 0; z < 32; z++)
        {
                sum += r[z];
                if (sum || z == 31)
                {
                        char c = '0' + r[z];

                        write(1, &c, 1);
                        count++;
                }
        }
        return (count);
}
