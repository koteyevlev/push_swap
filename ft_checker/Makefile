# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrystin <skrystin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:09:04 by skrystin          #+#    #+#              #
#    Updated: 2019/07/15 18:59:39 by skrystin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

HEADERS = $(includes/*.h)

all: $(NAME)
   
$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -o ../$(NAME) *.c ../ft_simple_sort.c -L libft/ -lft

clean:
	@rm -f *.o;
	@make -C libft/ clean

fclean: clean
	@rm -f ../$(NAME);
	@make -C libft/ fclean

re: fclean all
