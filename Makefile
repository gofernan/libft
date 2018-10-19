# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gofernan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 19:11:35 by gofernan          #+#    #+#              #
#    Updated: 2018/10/05 15:33:23 by gofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
ODIR = objs
SDIR = srcs
IDIR = include

PFDIR = ft_printf
ODIRPF = $(PFDIR)/objs
SDIRPF = $(PFDIR)/srcs

_DEPS = libft.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

CC = clang
FLAGS = -Wall -Wextra -Werror -g
_SRCS = ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_strlen.c \
		ft_strdup.c \
		ft_putchar.c \
		ft_strcpy.c \
		ft_putstr.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_itoa.c \
		ft_uitoa.c \
		ft_ltoa.c \
		ft_lltoa.c \
		ft_itoa_base.c \
		ft_uitoab.c \
		ft_atoi.c \
		ft_lstmap.c \
		ft_strsplit.c \
		ft_div_mod.c \
		ft_nlen.c \
		ft_wcslen.c \
		ft_strncpynp.c \
		ft_binary.c \
		ft_abs.c \
		get_next_line.c

_FTPF =	checkstr.c \
		checkstr_inside.c \
		checkstr_argorder.c \
		checkstr_flags.c \
		checkstr_fwidth.c \
		checkstr_prec.c \
		checkstr_length_hh.c \
		checkstr_length_h.c \
		checkstr_length_ll.c \
		checkstr_length_l.c \
		checkstr_length_j.c \
		checkstr_length_t.c \
		checkstr_length_z.c \
		checkstr_length_q.c \
		convsp.c \
		sconv.c \
		field_width.c \
		field_width_num.c \
		ft_printf.c \
		initialize_struct.c \
		precf.c \
		lsconv.c \
		utf8conv.c \
		onebyteconv.c \
		precfw.c \
		diconv.c \
		precdigits.c \
		flag_space.c \
		flag_plus.c \
		flag_sharp.c \
		uconv.c \
		oconv.c \
		xconv.c \
		cconv.c \
		lcconv.c \
		percent.c \
		pconv.c \
		bconv.c \
		store_write.c \
		checkstr_allargs.c \
		store_arglist.c \
		retr_arglist.c \
		sel_arglist.c \
		free_struct.c \
		checkstr_colors.c \
		checkstr_findcolor.c \
		fill_defaultv.c

_OBJS = $(_SRCS:.c=.o)
OBJS = $(patsubst %, $(ODIR)/%, $(_OBJS))

_OBJSPF = $(_FTPF:.c=.o)
OBJSPF = $(patsubst %, $(ODIRPF)/%, $(_OBJSPF))

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c $(FLAGS) -I$(DEPS) $< -o $@

$(ODIRPF)/%.o: $(SDIRPF)/%.c $(DEPS)
	$(CC) -c $(FLAGS) -I$(DEPS) $< -o $@

$(NAME): $(OBJS) $(OBJSPF)
	ar rc $(NAME) $(OBJS) $(OBJSPF)

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -f $(OBJSPF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY : all fclean clean re
