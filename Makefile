# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 20:54:29 by fjessi            #+#    #+#              #
#    Updated: 2019/12/12 20:17:29 by fjessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

INCLUDES = fillit.h

SRC = algoritm.c\
		align.c\
		check_charactar.c\
		check_count.c\
		check_tetrimer.c\
		create_square.c\
		figurka.c\
		get_buf.c\
		get_next_line.c\
		main.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJS)
		@gcc -Wall -Werror -Wextra -o $(NAME) $(OBJS) -L libft -lft

$(OBJS): %.o : %.c fillit.h
		gcc -Wall -Werror -Wextra -I $(INCLUDES) -c $<

lib:
	@make -C libft

clean:
	/bin/rm -f $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all