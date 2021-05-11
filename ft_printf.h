#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define FLAGS_COUNT 5
# define TYPES_COUNT 9

# define ALL_FLAGS "-+ #0"
# define ALL_TYPES "cspdiuxX%"

typedef struct s_specifier
{
	char				*position;
	char				*position_flags;
	char				*position_width;
	char				*position_accuracy;
	char				*position_type;
	char				*position_end;
	int					flags[FLAGS_COUNT];
	long				width;
	long				accuracy;
	int					type;
	void				*content;
	int					null_content;
	int					space;
	struct s_specifier	*next;
}						t_specifier;

int			ft_printf(const char *format, ...);
t_specifier	*get_specifiers(va_list ap, const char *format,
				long specifier_count);
long		get_specifiers_count(const char *format);
int			is_contain(const char *format, char *c);
int			add_flag(t_specifier *specifier, int flag);
int			add_type(t_specifier *specifier, int type);
int			ft_isdigit(char c);
char		*set_position_by_number(const char *format,
				t_specifier *specifier, long number);
char		*set_flags(t_specifier *specifier);
void		set_width(t_specifier *specifier, va_list ap);
char		*set_accuracy(t_specifier *specifier, va_list ap);
char		*set_type(t_specifier *specifier);
void		specifier_init(t_specifier *specifier);
void		free_specifiers(t_specifier *first);
void		*get_arg_by_position(va_list ap, long number);
char		*set_content(t_specifier *specifier, va_list ap);
long		handle_specifiers(t_specifier *first, char *format,
				long specifier_count);
long		handle_specifier(t_specifier *first, long number,
				char **format);
t_specifier	*get_needle_specifier(t_specifier *first, long number);
long		ft_strlen(char *str, t_specifier *specifier);
char		*int_to_str(long pointer, long system, int upper);
char		*char_to_str(char c);
char		*str_to_str(char *str);
char		*pointer_to_str(long pointer, t_specifier *specifier);
char		*digit_to_str(long digit);
char		*integer_to_str(int digit);
char		*unsigned_to_str(unsigned long digit);
char		*unsigned16_to_str(unsigned long digit);
char		*unsigned16up_to_str(unsigned long digit);
char		*percent_to_str(void);
void		debug_show_struct(t_specifier	*specifier);
char		*handle_width(t_specifier *specifier, char *content);
int			is_flag_exist(t_specifier *specifier, int flag);
char		*handle_accuracy(t_specifier *specifier, char *content);
char		*fill_str(char *content_new, long size, char c,
				t_specifier *specifier);
char		*copy_to_position(char *content, char *content_new,
				long position_for_copy, t_specifier *specifier);
int			is_type(char c);
int			is_flag(char c);
char		*fill_str(char *content_new, long size, char c,
				t_specifier *specifier);
char		*copy_to_position(char *content, char *content_new,
				long position_for_copy, t_specifier *specifier);
char		*copy_str_to_str(char *str, char *content);
char		*handle_width_forge(long *different, t_specifier **specifier,
				char **content_new, long *content_length);
char		*handle_accuracy_forge_a(t_specifier **specifier,
				char **content, char **content_new, int *negative);
char		*handle_accuracy_forge_b(long *size, t_specifier **specifier,
				char **content_new, char **content);
char		*copy_content(char *content, char *content_new, long size);
int			handle_negative(t_specifier *specifier, char *content);
int			is_type_exist(char *str, int c);
char		*handle_accuracy_forge_c(t_specifier **specifier, long *size,
				char **content_new, int negative);
int			p_get_size_of_digit(unsigned long long digit, int system);
void		p_is_minus(long *size, unsigned long long *pointer,
				long *system, int *negative);
char		*p_int_to_str(unsigned long long pointer,
				long system, int upper);
char		*content_at_settings(t_specifier *specifier, char *content);

#endif
