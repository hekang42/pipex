# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/07/01 17:39:23 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c redirect.c
SRC_B	= main.c redirect_bonus.c

SRCDIR	= ./srcs/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))
SRCS_B 	= $(addprefix $(SRCDIR), $(SRC_B))

OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME = libft.a

NAME	= pipex
BONUS	= pipex

GCC 	= GCC
GCCFLAG = -Wall -Werror -Wextra
# -g -fsanitize=address
RM 		= rm -f

%.o:		%.c
		$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

all:		$(NAME)

$(NAME):	$(LIBNAME) $(OBJS)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -o $(NAME) $(OBJS) $(LIBNAME)

$(BONUS):	$(LIBNAME) $(OBJS_B)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -o $(BONUS) $(OBJS_B) $(LIBNAME)

$(LIBNAME):
		@$(MAKE) -C $(LIBDIR) bonus
		@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)


bonus:		$(BONUS)

clean:
		$(RM) $(OBJS) $(OJBS_B)

fclean:		clean
		$(RM) $(NAME) $(LIBNAME)
		@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re bonus
