# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 20:26:38 by ljerk             #+#    #+#              #
#    Updated: 2020/02/19 20:35:52 by ljerk            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

.PHONY: all clean fclean re

SRC = 	main.c draw.c read_file.c keys.c

OBJ = $(SRC:.c=.o)

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $<

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@gcc -o fdf $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORK)

clean:
	@/bin/rm -f $(OBJ)
	@$(MAKE) -sC $(LIBFT_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	
re: 
	@$(MAKE) fclean
	@$(MAKE) all