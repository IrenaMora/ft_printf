NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	ft_printf.c \
			parser/get_specifiers.c parser/specifier_mediate_utils.c parser/specifier_utils.c \
			parser/string_utils.c	parser/va_handler.c \
			handler/accuracy.c handler/handle_specifier.c handler/handler.c \
			handler/types_translator.c handler/types_translator_b.c handler/utils.c \
			handler/utils_two.c handler/width.c handler/accuracy_forge.c \
			handler/pointer_handler.c

OBJ		=	ft_printf.o \
			get_specifiers.o specifier_mediate_utils.o specifier_utils.o \
			string_utils.o	va_handler.o \
			accuracy.o handle_specifier.o handler.o \
			types_translator.o types_translator_b.o utils.o \
			utils_two.o width.o accuracy_forge.o \
			pointer_handler.o

all		:	$(NAME)

$(NAME)	:	$(SRC) ft_printf.h
	$(CC) $(CFLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re 