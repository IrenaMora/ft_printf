#include "../ft_printf.h"

char	*fill_str(char *content_new, long size, char c, t_specifier *specifier)
{
	long	position;
	long	length;

	position = 0;
	length = ft_strlen(content_new, specifier);
	while (position != size)
	{
		content_new[position] = c;
		position++;
	}
	return (content_new);
}

char	*copy_to_position(char *content, char *content_new,
	long position_for_copy, t_specifier *specifier)
{
	long	length;
	long	position;

	length = ft_strlen(content, specifier);
	position = 0;
	while (position < length)
	{
		content_new[position_for_copy + position] = content[position];
		position++;
	}
	return (content_new);
}

char	*copy_str_to_str(char *str, char *content)
{
	long	length;
	long	position;

	position = 0;
	length = ft_strlen(content, NULL);
	while (position < length)
	{
		str[position] = content[position];
		position++;
	}
	return (str);
}

char	*handle_width_forge(long *different, t_specifier **specifier,
	char **content_new, long *content_length)
{
	*content_new = (char *)malloc(*content_length + *different + 1);
	if (content_new == NULL)
		return (NULL);
	(*content_new)[*content_length + *different] = '\0';
	if (*different > 0 && is_flag_exist(*specifier, '0')
		&& (*specifier)->accuracy != -1
		&& is_type_exist("diuxX", (*specifier)->type) != 0)
		fill_str(*content_new, *content_length + *different, ' ', *specifier);
	else if (*different > 0 && is_flag_exist(*specifier, '-'))
		fill_str(*content_new, *content_length + *different, ' ', *specifier);
	else if (*different > 0 && is_flag_exist(*specifier, '0'))
		fill_str(*content_new, *content_length + *different, '0', *specifier);
	else
		fill_str(*content_new, *content_length + *different, ' ', *specifier);
	return (*content_new);
}
