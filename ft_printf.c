#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	long		specifier_count;
	long		chars_printed;
	va_list		ap;
	t_specifier	*first;

	va_start(ap, format);
	specifier_count = get_specifiers_count(format);
	first = get_specifiers(ap, format, specifier_count);
	if (first == NULL && specifier_count != 0)
		return (-1);
	chars_printed = handle_specifiers(first, (char *)format, specifier_count);
	free_specifiers(first);
	va_end(ap);
	return (chars_printed);
}
