#include "../ft_printf.h"

long	ft_strlen(char *str, t_specifier *specifier)
{
	long	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	if (specifier != NULL && specifier->null_content)
		position++;
	return (position);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	add_flag(t_specifier *specifier, int flag)
{
	int	position;

	position = 0;
	while (position < FLAGS_COUNT)
	{
		if (specifier->flags[position] == 0)
		{
			specifier->flags[position] = flag;
			return (1);
		}
		else if (specifier->flags[position] == flag)
			return (0);
		position++;
	}
	return (0);
}

int	add_type(t_specifier *specifier, int type)
{
	int	position;

	position = 0;
	if (specifier->type == 0)
	{
		specifier->type = type;
		return (1);
	}
	else if (specifier->type == type)
		return (0);
	return (0);
}

int	is_contain(const char *format, char *c)
{
	long	position;

	position = 0;
	while (c[position] != '\0')
	{
		if (format[0] == c[position])
			return (c[position]);
		position++;
	}
	return (0);
}
