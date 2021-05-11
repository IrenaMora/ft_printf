#include "../ft_printf.h"

char	*integer_to_str(int digit)
{
	return (digit_to_str((long)digit));
}

char	*unsigned_to_str(unsigned long digit)
{
	return (digit_to_str((long)digit));
}

char	*unsigned16_to_str(unsigned long digit)
{
	char	*str;

	str = int_to_str((long)digit, 16, 87);
	return (str);
}

char	*unsigned16up_to_str(unsigned long digit)
{
	char	*str;

	str = int_to_str((long)digit, 16, 55);
	return (str);
}

char	*percent_to_str(void)
{
	char	*str;

	str = (char *)malloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
