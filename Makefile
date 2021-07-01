# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/07/01 14:28:34 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c redirect.c

SRCDIR	= ./srcs/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME = libft.a

NAME	= pipex

GCC 	= GCC
GCCFLAG = -Wall -Werror -Wextra
# -g -fsanitize=address
RM 		= rm -f

%.o:		%.c
		$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

$(NAME):	$(LIBNAME) $(MLXNAME) $(OBJS)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -o $(NAME) $(OBJS) $(LIBNAME)

$(LIBNAME):
		@$(MAKE) -C $(LIBDIR) bonus
		@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

all:		$(NAME)

bonus:		all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) $(LIBNAME) $(MLXNAME)
		@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
