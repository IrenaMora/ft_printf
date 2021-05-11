#include "../ft_printf.h"

long	write_till_text(char *format)
{
	long	position;

	position = 0;
	while (1)
	{
		if (format[position] == '%')
			return (position);
		else if (format[position] == '\0')
			return (position);
		write(1, format + position, 1);
		position++;
	}
}

long	handle_specifiers(t_specifier *first, char *format,
	long specifier_count)
{
	long	chars_to_console;
	long	last_to_console;
	long	number;

	chars_to_console = 0;
	number = 0;
	while (1)
	{
		last_to_console = write_till_text(format);
		chars_to_console += last_to_console;
		format += last_to_console;
		if (number >= specifier_count)
			break ;
		last_to_console = handle_specifier(first, number, &format);
		if (last_to_console == -1)
			return (-1);
		chars_to_console += last_to_console;
		number++;
	}
	return (chars_to_console);
}
