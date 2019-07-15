# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:09:04 by skrystin          #+#    #+#              #
#    Updated: 2019/07/15 14:37:05 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

HEADERS = $(includes/*.h)

all: $(NAME)
   
$(NAME):
	@make -C ft_checker/ fclean && make -C ft_checker/ re
	@gcc -o push_swap main.c ft_simple_sort.c ft_simple_sort_two.c ft_checker/ft*.c -L ft_checker/libft -lft

clean:
	@make -C ft_checker/ clean

fclean: clean
	@make -C ft_checker/ fclean
	@rm push_swap

re: fclean all
