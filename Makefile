# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alibourb <alibourb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 14:24:47 by alibourb          #+#    #+#              #
#    Updated: 2023/03/01 14:24:47 by alibourb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = \
		create_map.c initialization.c parsing.c \
		display_map.c render.c handle.c win_or_lose.c map_path.c \
		printers.c ft_printf.c ft_putnbr.c ft_putptr.c main.c \
		so_long_utils_1.c so_long_utils_2.c errors.c \
		get_next_line.c get_next_line_utils.c \

OBJ = $(SRC:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -g
HEADERS 		= -I ./includes

all:		path	$(NAME)

path:
		make -C mlx_linux/

%.o: %.c
	$(CC) $(HEADERS) -Wall -Wextra -Werror -g -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(HEADERS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -g -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

docker-build:
	docker build -t so_long .

docker-run: docker-build
	docker run -it --rm -e DISPLAY=$(DISPLAY) -v /tmp/.X11-unix:/tmp/.X11-unix -v "${PWD}:/so_long" so_long

.PHONY:			all clean fclean re docker-build docker-run
