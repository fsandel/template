# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsandel <fsandel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 10:30:26 by fsandel           #+#    #+#              #
#    Updated: 2023/01/30 13:05:06 by fsandel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	template
SRC				=	main.c template.c utils.c
OBJ				=	$(SRC:.c=.o)
CC				=	cc
CFLAGS			=	

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFT)


%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS)


clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all



$(LIBFT):
		make -C $(LIBFT_DIR)

libft:	$(LIBFT)

.PHONY: all clean fclean re