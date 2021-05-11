#include "../ft_printf.h"

char	*handle_accuracy_forge_a(t_specifier **specifier, char **content,
	char **content_new, int *negative)
{
	if ((*specifier)->accuracy < 0)
		return (*content);
	else if ((*content)[0] == '0' && (*content)[1] == '\0')
	{
		(*content_new) = (char *)malloc(1);
		if (*content_new == NULL)
		{
			*negative = -1;
			return (NULL);
		}
		(*content_new)[0] = '\0';
		free(*content);
		return (handle_accuracy(*specifier, *content_new));
	}
	*negative = handle_negative(*specifier, *content);
	return (NULL);
}

char	*handle_accuracy_forge_b(long *size, t_specifier **specifier,
	char **content_new, char **content)
{
	if (*size > (*specifier)->accuracy)
		*size = (*specifier)->accuracy;
	*content_new = (char *)malloc(*size + 1);
	if (*content_new == NULL)
		return (NULL);
	(*content_new)[*size] = '\0';
	copy_content(*content, *content_new, *size);
	return (*content_new);
}

char	*handle_accuracy_forge_c(t_specifier **specifier, long *size,
	char **content_new, int negative)
{
	if ((*specifier)->accuracy > *size)
		*size = (*specifier)->accuracy;
	*content_new = (char *)malloc(negative + *size + 1);
	if (*content_new == NULL)
		return (NULL);
	(*content_new)[negative + *size] = '\0';
	fill_str(*content_new, *size, '0', *specifier);
	return (*content_new);
}
