# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhill <nhill@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 16:28:39 by nhill             #+#    #+#              #
#    Updated: 2021/02/23 18:01:16 by nhill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc


SRC =    ft_strdup.c 		ft_bzero.c 			ft_isalpha.c  	ft_isdigit.c  \
		   ft_memccpy.c  		ft_memcmp.c   		ft_memmove.c  	ft_strchr.c   \
   		ft_strlcpy.c  		ft_strncmp.c  		ft_strrchr.c  	ft_toupper.c  \
   		ft_atoi.c     		ft_isalnum.c  		ft_isascii.c  	ft_isprint.c  \
   		ft_memchr.c   		ft_memcpy.c   		ft_memset.c   	ft_strlcat.c  \
   		ft_strlen.c   		ft_strnstr.c  		ft_tolower.c 	ft_calloc.c   \
   		ft_strdup.c 		ft_substr.c 		ft_strjoin.c 	ft_strtrim.c  \
   		ft_split.c 			ft_itoa.c 			ft_strmapi.c   	ft_putchar_fd.c\
   		ft_putstr_fd.c 	ft_putendl_fd.c 	ft_putnbr_fd.c		ft_lstnew.c \
         ft_lstadd_front.c    ft_lstadd_front.c    ft_lstadd_back.c ft_lstsize.c\
         ft_lstlast.c         ft_lstdelone.c       ft_lstclear.c  ft_lstiter.c\
         ft_lstmap.c			ft_strcpy.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONSRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -c

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@echo "$(F_GREEN)Cleaned! $(F_NONE)"

fclean: clean
	rm -f $(NAME)
	@echo "$(F_ORANGE)FCleaned! $(F_NONE)"

re: fclean all

norm:
	norminette *.c *.h

.PHONY: clean fclean
