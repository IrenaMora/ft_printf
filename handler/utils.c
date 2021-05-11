#include "../ft_printf.h"

int	get_size_of_digit(long digit, int system)
{
	int	size;

	if (digit == 0)
		return (1);
	size = 0;
	while (digit != 0)
	{
		digit /= system;
		size++;
	}
	return (size);
}

void	is_minus(long *size, long *pointer, long *system, int *negative)
{
	*negative = 0;
	*size = get_size_of_digit(*pointer, *system);
	if (*pointer < 0)
	{
		*negative = 1;
		*pointer = -*pointer;
		(*size)++;
	}
}

char	*int_to_str(long pointer, long system, int upper)
{
	int		negative;
	char	*str;
	long	size;
	long	position;

	position = 0;
	is_minus(&size, &pointer, &system, &negative);
	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	while (pointer != 0)
	{
		if (pointer % system < 10)
			str[size - position - 1] = (pointer % system) + 48;
		else
			str[size - position - 1] = (pointer % system) + upper;
		pointer /= system;
		position++;
	}
	if (negative == 1)
		str[0] = '-';
	str[size] = '\0';
	return (str);
}

t_specifier	*get_needle_specifier(t_specifier *first, long number)
{
	t_specifier	*needle_specifier;
	long		position;

	needle_specifier = first;
	position = 0;
	while (position != number)
	{
		needle_specifier = needle_specifier->next;
		position++;
	}
	return (needle_specifier);
}

int	is_flag_exist(t_specifier *specifier, int flag)
{
	long	position;

	position = 0;
	while (position < FLAGS_COUNT)
		if ((specifier->flags)[position++] == flag)
			return (1);
	return (0);
}
