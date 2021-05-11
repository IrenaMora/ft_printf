#include "../ft_printf.h"

char	*copy_content(char *content, char *content_new, long size)
{
	long	position;

	position = 0;
	while (position < size)
	{
		content_new[position] = content[position];
		position++;
	}
	return (content_new);
}

int	handle_negative(t_specifier *specifier, char *content)
{
	long	length;
	long	position;

	if (specifier->type == 'c' || specifier->type == 's'
		|| specifier->type == 'p' || specifier->type == '%'
		|| content[0] != '-')
		return (0);
	if (content[0] == '-')
	{
		position = 0;
		length = ft_strlen(content, NULL);
		while (length - position + 1 != 0)
		{
			content[position] = content[position + 1];
			position++;
		}
		content[position] = '\0';
	}
	return (1);
}

char	*add_for_negative(char *content)
{
	long	length;
	long	position;

	length = ft_strlen(content, NULL);
	position = 0;
	while (length - position != 0)
	{
		content[length - position] = content[length - position - 1];
		position++;
	}
	content[0] = '-';
	content[length + 1] = '\0';
	return (content);
}

char	*copy_to_pos(char *content, char *content_new,
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
	content_new[position_for_copy + position] = '\0';
	return (content_new);
}

char	*handle_accuracy(t_specifier *specifier, char *content)
{
	long	size;
	char	*content_new;
	int		negative;
	char	*forge;

	forge = handle_accuracy_forge_a(&specifier, &content,
			&content_new, &negative);
	if (forge != NULL || negative == -1)
		return (forge);
	size = ft_strlen(content, NULL);
	if (specifier->type == 's')
		handle_accuracy_forge_b(&size, &specifier, &content_new, &content);
	else
	{
		handle_accuracy_forge_c(&specifier, &size, &content_new, negative);
		if (content_new != NULL)
		{
			copy_to_pos(content, content_new, size
				- ft_strlen(content, NULL), specifier);
			if (negative != 0)
				add_for_negative(content_new);
		}
	}
	free(content);
	return (content_new);
}
