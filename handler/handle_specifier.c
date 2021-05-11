#include "../ft_printf.h"

long	write_str(t_specifier *specifier, char *content)
{
	long	position;
	long	zeros;

	position = 0;
	zeros = 0;
	content = content_at_settings(specifier, content);
	if (!content)
		return (-1);
	if (specifier->space)
		write(1, " ", 1);
	if (specifier->null_content)
		zeros = -1;
	if (content[position] == '\0')
		zeros++;
	while (zeros != 1)
	{
		write(1, content + position, 1);
		position++;
		if (content[position] == '\0')
			zeros++;
	}
	free(content);
	return (position);
}

char	*handle_pointer(t_specifier *specifier, char *content)
{
	long	length;
	char	*content_new;

	length = ft_strlen(content, specifier);
	content_new = (char *)malloc(length + 2 + 1);
	if (content_new == NULL)
		return (NULL);
	content_new[0] = '0';
	content_new[1] = 'x';
	copy_to_position(content, content_new, 2, NULL);
	content_new[length + 2] = '\0';
	free(content);
	return (content_new);
}

char	*content_at_settings(t_specifier *specifier, char *content)
{
	if (content == NULL)
		return (NULL);
	if (specifier->type == 'p')
		content = handle_pointer(specifier, content);
	if (content == NULL)
		return (NULL);
	if (specifier->accuracy != -1 && specifier->type != '%')
		content = handle_accuracy(specifier, content);
	if (content == NULL)
		return (NULL);
	if (specifier->width != -1)
		content = handle_width(specifier, content);
	if (content == NULL)
		return (NULL);
	return (content);
}

long	handle_content(t_specifier *specifier)
{
	long	chars_printed;
	char	*content;

	if (specifier->type == 'c')
		content = char_to_str((char)(specifier->content));
	else if (specifier->type == 's')
		content = str_to_str((char *)(specifier->content));
	else if (specifier->type == 'p')
		content = pointer_to_str((long)specifier->content, specifier);
	else if (specifier->type == 'd')
		content = digit_to_str((int)specifier->content);
	else if (specifier->type == 'i')
		content = integer_to_str((int)specifier->content);
	else if (specifier->type == 'u')
		content = unsigned_to_str((unsigned int)specifier->content);
	else if (specifier->type == 'x')
		content = unsigned16_to_str((unsigned int)specifier->content);
	else if (specifier->type == 'X')
		content = unsigned16up_to_str((unsigned int)specifier->content);
	else if (specifier->type == '%')
		content = percent_to_str();
	else
		content = char_to_str('\0');
	chars_printed = write_str(specifier, content);
	return (chars_printed);
}

long	handle_specifier(t_specifier *first, long number, char **format)
{
	long		chars_printed;
	t_specifier	*specifier;

	specifier = get_needle_specifier(first, number);
	if (specifier->type == '?')
		return (0);
	chars_printed = handle_content(specifier);
	*format += (specifier->position_end - specifier->position);
	return (chars_printed);
}
