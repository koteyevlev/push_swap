# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:09:04 by skrystin          #+#    #+#              #
#    Updated: 2019/07/12 19:39:52 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

HEADERS = $(includes/*.h)

all: $(NAME)
   
$(NAME):
	@make -C ft_checker/ fclean && make -C ft_checker/ re
	@gcc -o push_swap main.c ft_checker/ft*.c -L ft_checker/libft -lft

clean:
	@make -C ft_checker/ clean

fclean: clean
	@make -C ft_checker/ fclean

re: fclean all
