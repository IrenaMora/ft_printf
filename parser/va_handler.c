#include "../ft_printf.h"

int	is_type(char c)
{
	long	position;

	position = 0;
	while (position < TYPES_COUNT)
		if (ALL_TYPES[position++] == c)
			return (1);
	return (0);
}

int	is_flag(char c)
{
	long	position;

	position = 0;
	while (position < FLAGS_COUNT)
		if (ALL_FLAGS[position++] == c)
			return (1);
	return (0);
}

void	*get_arg_by_position(va_list ap, long number)
{
	long	position;
	void	*content;
	va_list	ap_copy;

	position = 0;
	va_copy(ap_copy, ap);
	while (position <= number)
	{
		content = va_arg(ap, void *);
		position++;
	}
	va_copy(ap, ap_copy);
	return (content);
}
