# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 11:46:14 by aguemazi          #+#    #+#              #
#    Updated: 2022/05/09 09:25:54 by aguemazi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pipex.c ft_verif.c ft_get_path.c ft_free_doublechar.c ft_exec_command.c

OBJS = $(SRC:.c=.o)

NAME = libftpipex.a

.c.o:
			@ gcc -Wall -Wextra -Werror -c -I./src $< -o ${<:.c=.o}

$(NAME) : 	$(OBJS)
			$(MAKE) -C Libft/
			cp Libft/libft.a $(NAME)
			ar rcs $@ $^
			gcc -Wall -Wextra -Werror  pipex.c libftpipex.a -o pipex

all : ${NAME}

re :		fclean all

clean :
			rm -f ${OBJS}
			$(MAKE) clean -C Libft/

fclean : clean
			$(MAKE) fclean -C Libft/
			rm -f ${OBJS}
			rm -f  ${NAME}

.phony : all flean clean re