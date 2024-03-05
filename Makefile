# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akloster <akloster@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:52:12 by akloster          #+#    #+#              #
#    Updated: 2024/02/05 12:05:41 by akloster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	gcc

NAME			=	push_swap

CFLAGS			=	-Wall -Wextra -Werror

SRC				=	helper_fct.c helper_fct_1.c helper_fct_2.c push_swap.c \
					operations.c algo.c operation_2.c helper_fct_3.c \
					helper_fct_4.c throw_aways.c

LIBFT			=	libft/libft.a

OBJ_DIR			=	objs/

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

RM				=	rm -rf

$(NAME):		$(OBJ_DIR) $(OBJ)
				make bonus -C ./libft
				$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $@

all:			$(NAME)

$(OBJ_DIR)%.o:%.c
				gcc $(CFLAGS) -I . -c $< -o $@

$(OBJ_DIR):	
				@mkdir -p $(OBJ_DIR)

clean:
				make clean -C libft
				$(RM) $(OBJ)

fclean:			clean
				make fclean -C libft
				$(RM) $(OBJ) $(NAME) $(OBJ_DIR)
				

re:				fclean $(NAME)


.PHONY:			all clean fclean re