# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:09:04 by skrystin          #+#    #+#              #
#    Updated: 2019/07/11 18:58:29 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERS = $(includes/*.h)

all: $(NAME)
   
$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -o $(NAME) *.c -L libft/ -lft

clean:
	@rm -f *.o;
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME);
	@make -C libft/ fclean

re: fclean all
