# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmanie <gmanie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/11 13:09:04 by skrystin          #+#    #+#              #
#    Updated: 2019/06/24 13:26:01 by gmanie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC1 = *.c

HEADERS = $(*.h)

all: $(NAME)
   
$(NAME):
	@gcc -c -Wall -Wextra -Werror -std=c99 $(SRC1) $(HEADERS) 
	@ar rc $(NAME) *.o;
	@ranlib $(NAME);

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@rm -f *.h.gch

re: fclean all
