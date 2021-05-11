#include "../ft_printf.h"

char	*char_to_str(char c)
{
	char	*content;

	content = (char *)malloc(2);
	if (content == NULL)
		return (content);
	content[0] = c;
	content[1] = '\0';
	return (content);
}

char	*str_to_str(char *str)
{
	char	*content;
	long	position;
	long	content_length;

	if (str == NULL)
	{
		content = (char *)malloc(6 + 1);
		if (content == NULL)
			return (NULL);
		copy_str_to_str(content, "(null)");
		return (content);
	}
	position = 0;
	content_length = ft_strlen(str, NULL);
	content = (char *)malloc(content_length + 1);
	if (content == NULL)
		return (NULL);
	while (position < content_length)
	{
		content[position] = str[position];
		position++;
	}
	content[position] = '\0';
	return (content);
}

char	*pointer_to_str(long pointer, t_specifier *specifier)
{
	char	*str;

	if (specifier->content == NULL && specifier->accuracy != -1)
	{
		str = (char *)malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
	}
	else
		str = p_int_to_str(pointer, 16, 87);
	return (str);
}

char	*digit_to_str(long digit)
{
	char	*str;

	str = int_to_str(digit, 10, 87);
	return (str);
}
