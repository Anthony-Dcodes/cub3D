NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes

GNL_SRC_DIR = srcs/get_next_line
LIBFT_SRC_DIR = srcs/lib_ft
PRINTF_SRC_DIR = srcs/printf
LIBFTPP_SRC_DIR = srcs/lib_ftpp

SRCS = \
	$(GNL_SRC_DIR)/get_next_line_utils.c \
	$(GNL_SRC_DIR)/get_next_line.c \
	$(LIBFT_SRC_DIR)/ft_atoi.c \
	$(LIBFT_SRC_DIR)/ft_bzero.c \
	$(LIBFT_SRC_DIR)/ft_calloc.c \
	$(LIBFT_SRC_DIR)/ft_isalnum.c \
	$(LIBFT_SRC_DIR)/ft_isalpha.c \
	$(LIBFT_SRC_DIR)/ft_isascii.c \
	$(LIBFT_SRC_DIR)/ft_isdigit.c \
	$(LIBFT_SRC_DIR)/ft_isprint.c \
	$(LIBFT_SRC_DIR)/ft_itoa.c \
	$(LIBFT_SRC_DIR)/ft_lstadd_back_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstadd_front_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstclear_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstdelone_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstiter_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstlast_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstmap_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstnew_bonus.c \
	$(LIBFT_SRC_DIR)/ft_lstsize_bonus.c \
	$(LIBFT_SRC_DIR)/ft_memchr.c \
	$(LIBFT_SRC_DIR)/ft_memcmp.c \
	$(LIBFT_SRC_DIR)/ft_memcpy.c \
	$(LIBFT_SRC_DIR)/ft_memmove.c \
	$(LIBFT_SRC_DIR)/ft_memset.c \
	$(LIBFT_SRC_DIR)/ft_putchar_fd.c \
	$(LIBFT_SRC_DIR)/ft_putendl_fd.c \
	$(LIBFT_SRC_DIR)/ft_putnbr_fd.c \
	$(LIBFT_SRC_DIR)/ft_putstr_fd.c \
	$(LIBFT_SRC_DIR)/ft_split.c \
	$(LIBFT_SRC_DIR)/ft_strchr.c \
	$(LIBFT_SRC_DIR)/ft_strdup.c \
	$(LIBFT_SRC_DIR)/ft_striteri.c \
	$(LIBFT_SRC_DIR)/ft_strjoin.c \
	$(LIBFT_SRC_DIR)/ft_strlcat.c \
	$(LIBFT_SRC_DIR)/ft_strlcpy.c \
	$(LIBFT_SRC_DIR)/ft_strlen.c \
	$(LIBFT_SRC_DIR)/ft_strmapi.c \
	$(LIBFT_SRC_DIR)/ft_strncmp.c \
	$(LIBFT_SRC_DIR)/ft_strnstr.c \
	$(LIBFT_SRC_DIR)/ft_strrchr.c \
	$(LIBFT_SRC_DIR)/ft_strtrim.c \
	$(LIBFT_SRC_DIR)/ft_substr.c \
	$(LIBFT_SRC_DIR)/ft_tolower.c \
	$(LIBFT_SRC_DIR)/ft_toupper.c \
	$(LIBFTPP_SRC_DIR)/ft_atof.c \
	$(LIBFTPP_SRC_DIR)/ft_int2hex.c \
	$(LIBFTPP_SRC_DIR)/ft_str_reverse.c \
	$(LIBFTPP_SRC_DIR)/ft_uint2str.c \
	$(LIBFTPP_SRC_DIR)/ft_uintlen.c \
	$(LIBFTPP_SRC_DIR)/ft_ulong2hex.c \
	$(LIBFTPP_SRC_DIR)/ft_atoi_safe.c \
	$(LIBFTPP_SRC_DIR)/ft_sort_array.c \
	$(PRINTF_SRC_DIR)/common_print.c \
	$(PRINTF_SRC_DIR)/ft_printf.c \
	$(PRINTF_SRC_DIR)/handle_diu_formats.c \
	$(PRINTF_SRC_DIR)/handle_sc_formats.c \
	$(PRINTF_SRC_DIR)/handle_xxp_formats.c

HEADERS = \
	includes/ft_printf.h \
	includes/get_next_line.h \
	includes/libft.h \
	includes/libftpp.h

OBJS = $(SRCS:.c=.o)

# --- Rebuild if headers change ---
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
