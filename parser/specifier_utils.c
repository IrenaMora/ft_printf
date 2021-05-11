#include "../ft_printf.h"

void	specifier_init(t_specifier *specifier)
{
	long	position;

	position = 0;
	specifier->position = NULL;
	specifier->position_flags = NULL;
	specifier->position_width = NULL;
	specifier->width = -1;
	specifier->accuracy = -1;
	specifier->content = NULL;
	specifier->next = NULL;
	specifier->null_content = 0;
	specifier->space = 0;
	while (position < FLAGS_COUNT)
	{
		specifier->flags[position] = 0;
		position++;
	}
}

const char	*get_next_position(const char *format)
{
	long		position;
	const char	*next_format;

	position = 1;
	next_format = format;
	if (next_format[position] == ' ')
		position++;
	while (is_flag(next_format[position]))
		position++;
	while (ft_isdigit(next_format[position]))
		position++;
	if (next_format[position] == '.')
	{
		position++;
		while (ft_isdigit(next_format[position]))
			position++;
	}
	if (next_format[position] == '%')
		return (next_format + position);
	return (NULL);
}

long	get_specifiers_count(const char *format)
{
	long		position;
	long	 	specifiers_count;

	position = 0;
	specifiers_count = 0;
	while (format[position] != '\0')
	{
		if (format[position] == '%')
		{
			position++;
			while (!is_type(format[position]) && format[position] != '\0')
				position++;
			specifiers_count++;
		}
		position++;
	}
	return (specifiers_count);
}

char	*set_position_by_number(const char *format,
			t_specifier *specifier, long number)
{
	long	position;
	long	specifiers_count;

	position = 0;
	specifiers_count = 0;
	while (format[position] != '\0')
	{
		while (format[position] != '\0' && format[position] != '%')
			position++;
		if (specifiers_count == number)
		{
			specifier->position = (char *)(format + position);
			specifier->position_flags = (char *)(format + position + 1);
			return (specifier->position);
		}
		position++;
		while (format[position] != '\0' && !is_type(format[position]))
			position++;
		position++;
		specifiers_count++;
	}
	return (NULL);
}

void	free_specifiers(t_specifier *first)
{
	t_specifier	*current;
	t_specifier	*next;

	current = first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
