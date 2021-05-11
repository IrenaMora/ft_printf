#include "../ft_printf.h"

char	*set_flags(t_specifier *specifier)
{
	int		flag;
	char	*format;

	format = specifier->position_flags;
	if (*format == ' ')
	{
		specifier->space = 1;
		format++;
	}
	flag = is_contain(format, ALL_FLAGS);
	while (flag != 0)
	{
		add_flag(specifier, flag);
		format++;
		flag = is_contain(format, ALL_FLAGS);
	}
	specifier->position_width = format;
	return (format);
}

void	set_width(t_specifier *specifier, va_list ap)
{
	long	digit;
	char	*format;

	digit = 0;
	format = specifier->position_width;
	if (*format == '*')
	{
		specifier->width = va_arg(ap, int);
		if ((int)(specifier->width) < 0)
		{
			add_flag(specifier, '-');
			specifier->width = (int)((specifier->width) * -1);
		}
		format++;
	}
	else if (ft_isdigit(*format))
	{
		while (ft_isdigit(*format))
		{
			digit = digit * 10 + (*format - '0');
			format++;
		}
		specifier->width = digit;
	}
	specifier->position_accuracy = format;
}

char	*set_accuracy(t_specifier *specifier, va_list ap)
{
	long	digit;
	char	*format;

	digit = 0;
	format = specifier->position_accuracy;
	if (format[0] == '.' && format[1] == '*')
	{
		specifier->accuracy = va_arg(ap, long);
		if ((int)(specifier->accuracy) < 0)
			specifier->accuracy = -1;
		format += 2;
	}
	else if (format[0] == '.')
	{
		format++;
		while (ft_isdigit(*format))
		{
			digit = digit * 10 + (*format - '0');
			format++;
		}
		specifier->accuracy = digit;
	}
	specifier->position_type = format;
	return (format);
}

char	*set_type(t_specifier *specifier)
{
	int		type;
	char	*format;

	format = specifier->position_type;
	type = is_contain(format, ALL_TYPES);
	if (type == 0)
		specifier->type = '?';
	else
		specifier->type = type;
	specifier->position_end = ++format;
	return (format);
}

char	*set_content(t_specifier *specifier, va_list ap)
{
	if (specifier->type == '?')
		specifier->content = "?";
	else if (specifier->type != '%')
		specifier->content = va_arg(ap, void *);
	if (specifier->type == 'c' && (char)(specifier->content) == '\0')
		specifier->null_content = 1;
	return (specifier->content);
}
