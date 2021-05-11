#include "../ft_printf.h"

char	*move_str(char *content, long position_to, long position_from)
{
	long	length;

	length = ft_strlen(content, NULL);
	while (position_from < length)
	{
		content[position_to] = content[position_from];
		position_to++;
		position_from++;
	}
	content[position_to] = '\0';
	return (content);
}

int	negative_handler(t_specifier *specifier, char *content)
{
	if (specifier->type == 'c' || specifier->type == 's'
		|| specifier->type == 'p' || specifier->type == '%')
		return (0);
	if (*content != '-')
		return (0);
	content = move_str(content, 0, 1);
	return (1);
}

char	*add_negative(t_specifier *specifier, char *content)
{
	long	length;
	long	position;

	length = ft_strlen(content, specifier);
	position = 0;
	while (position < length)
	{
		content[length - position - 1] = content[length - position - 2];
		position++;
	}
	position = 1;
	while (content[position] == ' ')
		position++;
	if (position != 1)
		content[0] = ' ';
	content[position - 1] = '-';
	return (content);
}

int	is_type_exist(char *str, int c)
{
	long	length;
	long	position;

	length = ft_strlen(str, NULL);
	position = 0;
	while (position < length)
		if (str[position++] == c)
			return (1);
	return (0);
}

char	*handle_width(t_specifier *specifier, char *content)
{
	long	length;
	long	different;
	char	*content_new;
	int		handler_negative;

	length = ft_strlen(content, specifier);
	different = 0;
	handler_negative = negative_handler(specifier, content);
	if (specifier->width > length)
		different = specifier->width - length;
	if (!handle_width_forge(&different, &specifier, &content_new, &length))
	{
		free(content);
		return (NULL);
	}
	if (is_flag_exist(specifier, '-'))
		copy_to_position(content, content_new, 0, specifier);
	else if (is_flag_exist(specifier, '0'))
		copy_to_position(content, content_new, different, specifier);
	else
		copy_to_position(content, content_new, different, specifier);
	if (handler_negative == 1)
		content_new = add_negative(specifier, content_new);
	free(content);
	return (content_new);
}
