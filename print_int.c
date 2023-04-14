#include "main.h"

/**
 * print_int - Prints an int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
        int x = BUFF_SIZE - 2;
        int is_negative = 0;
        long int z = va_arg(types, long int);
        unsigned long int num;

        z = convert_size_number(z, size);

        if (0 == z)
                buffer[x--] = '0';

        buffer[BUFF_SIZE - 1] = '\0';
        num = (unsigned long int)z;

        if (0 > z)
        {
                num = (unsigned long int)((-1) * z);
                is_negative = 1;
        }

        while (num > 0)
        {
                buffer[x--] = (num % 10) + '0';
                num /= 10;
        }
        x++;

        return (write_number(is_negative, x, buffer, flags, width, precision, size));
}
