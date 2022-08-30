# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 15:24:21 by jrasser           #+#    #+#              #
#    Updated: 2022/08/30 18:41:28 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
ERASE		= \033[2K\r
END			= \033[0m
CHECK 		= ✓

SRCS 		= $(wildcard *.cpp) $(wildcard srcs/**.cpp)
NAME		= prog
OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
RM			= @rm -rf
CC			= g++
CFLAGS		= -std=c++98 -Wall -Wextra
CPPFLAGS	= -I. -I./class -I./includes
DEBEUG		= -g -fsanitize=address

objs/%.o: *%.cpp
			@mkdir -p $(OBJS_DIR)
			@${CC} $(CPPFLAGS) -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"$(ERASE) ${BLU}$ [BUILD]${RST} '$<' $(END)"

objs/%.o: srcs/**%.cpp
			@mkdir -p $(OBJS_DIR)
			@${CC} $(CPPFLAGS) -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"$(ERASE) ${BLU}$ [BUILD]${RST} '$<' $(END)"

${NAME}	:	${OBJS}
			@${CC} ${OBJS} -o $(NAME) ${CFLAGS} ${DEBEUG}
			@echo "$(ERASE)$(GRN) [Successfully compiled]$(END)	$(CHECK) \n"
			@echo "Executable ./$(NAME) \n"

all :		${NAME}

clean :
			${RM} $(OBJS)
			@echo "$(GRN) [Clean]$(END) 			$(CHECK)"

fclean :	clean
			${RM} ${NAME}
			@echo "$(GRN) [Fclean]$(END) 			$(CHECK)"

re : 		fclean all

.PHONY:		all clean fclean re