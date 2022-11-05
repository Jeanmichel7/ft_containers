# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrasser <jrasser@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/01 15:24:21 by jrasser           #+#    #+#              #
#    Updated: 2022/11/05 01:41:05 by jrasser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
ERASE		= \033[2K\r
END			= \033[0m
CHECK 		= ✓

SRCS 		= $(wildcard *.cpp) $(wildcard srcs/**.cpp)
SRCS_FT = $(wildcard srcs/rendu/**.cpp)

NAME				= tester
TESTER_FT 	= tester_ft
TESTER_STD 	= tester_std

OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))
OBJS_BIN = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_FT:.cpp=.o)))
RM			= @rm -rf
CC			= g++
CFLAGS		= -Wall -Wextra -std=c++98
CPPFLAGS	= -I. -I./class -I./includes
DEBEUG		= -g

objs/%.o: *%.cpp
			@mkdir -p $(OBJS_DIR)
			@${CC} $(CPPFLAGS) -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"$(ERASE) ${BLU}$ [BUILD]${RST} '$<' $(END)"

objs/%.o: srcs/**%.cpp
			@mkdir -p $(OBJS_DIR)
			@${CC} $(CPPFLAGS) -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"$(ERASE) ${BLU}$ [BUILD]${RST} '$<' $(END)"

objs/%.o: srcs/rendu/**%.cpp
			@mkdir -p $(OBJS_DIR)
			@${CC} $(CPPFLAGS) -o $@ -c $< ${CFLAGS} ${DEBEUG}
			@printf	"$(ERASE) ${BLU}$ [BUILD]${RST} '$<' $(END)"



${NAME}	:	${OBJS}
			@${CC} ${OBJS} -o $(NAME) ${CFLAGS} ${DEBEUG}
			@echo "$(ERASE)$(GRN) [Successfully compiled]$(END)	$(CHECK)"
			@echo "	Executable ./$(NAME) \n"


all :	bin_ft bin_std ${NAME}

bin : bin_ft bin_std

bin_ft : 
			@${CC} -DSTL_TYPE=ft $(wildcard srcs/rendu/**.cpp) -o $(TESTER_FT) ${CFLAGS} ${DEBEUG}
			@echo "$(ERASE)$(GRN) [Tester FT Successfully compiled]$(END)	$(CHECK)"
			@echo "	Executable ./$(TESTER_FT) \n"

bin_std : 
			@${CC} -DSTL_TYPE=std $(wildcard srcs/rendu/**.cpp) -o $(TESTER_STD) ${CFLAGS} ${DEBEUG}
			@echo "$(ERASE)$(GRN) [Tester STD Successfully compiled]$(END)	$(CHECK)"
			@echo "	Executable ./$(TESTER_STD) \n"

clean :
			${RM} $(OBJS) ${OBJS_BIN}
			@echo "$(GRN) [Clean]$(END) 			$(CHECK)"

fclean :	clean
			${RM} ${NAME} ${TESTER_FT} ${TESTER_STD}
			@echo "$(GRN) [Fclean]$(END) 			$(CHECK)"

re : 		fclean all

.PHONY:		all clean fclean re

# make fclean && make bin && ./tester_ft > testerft.txt && ./tester_std > testerstd.txt && diff testerft.txt testerstd.txt
# make fclean && make bin && ./tester_ft > testerft.txt && ./tester_std > testerstd.txt && diff testerstd.txt testerft.txt > diff.txt
# ./tester_ft > testerft.txt && ./tester_std > testerstd.txt && diff testerstd.txt testerft.txt > diff.txt