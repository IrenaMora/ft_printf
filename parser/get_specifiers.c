#include "../ft_printf.h"

void	set_default_params(t_specifier *tmp, const char *format,
	va_list ap, long position)
{
	if (tmp == NULL)
		return ;
	specifier_init(tmp);
	set_position_by_number(format, tmp, position);
	set_flags(tmp);
	set_width(tmp, ap);
	set_accuracy(tmp, ap);
	set_type(tmp);
	set_content(tmp, ap);
}

t_specifier	*get_specifiers(va_list ap, const char *format,
			long specifier_count)
{
	long		position;
	t_specifier	*first;
	t_specifier	*current;
	t_specifier	*tmp;

	position = 0;
	first = NULL;
	while (position < specifier_count)
	{
		tmp = malloc(sizeof(t_specifier));
		set_default_params(tmp, format, ap, position);
		if (tmp->type == '?')
		{
			free_specifiers(first);
			return (NULL);
		}
		if (tmp == NULL || first != NULL)
			current->next = tmp;
		else
			first = tmp;
		current = tmp;
		position++;
	}
	return (first);
}
