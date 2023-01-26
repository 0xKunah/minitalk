# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 12:02:00 by dbiguene          #+#    #+#              #
#    Updated: 2023/01/18 12:02:00 by dbiguene         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	minitalk

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Libs variables ---- #

LIBFT			=   libft/libft.a

# ---- Client Files ---- #

CL_HEADERS_LIST	=	minitalk.h

CL_SRCS_LIST	=	main.c		parser.c	\
					signal.c

CL_HEADERS		=	${CL_HEADERS_LIST:%.h=${DIR_HEADERS}client/%.h}

CL_OBJS			=	${CL_SRCS_LIST:%.c=${DIR_OBJS}client/%.o}

# ---- Server Files ---- #

SV_HEADERS_LIST	=	minitalk.h

SV_SRCS_LIST	=	main.c	list.c

SV_HEADERS		=	${SV_HEADERS_LIST:%.h=${DIR_HEADERS}server/%.h}

SV_OBJS			=	${SV_SRCS_LIST:%.c=${DIR_OBJS}server/%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

FRAMEWORKS		=	-Llibft -lft

# ---- OS Variables ---- #

UNAME			=	$(shell uname -s)

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	client server

client			:	${CL_OBJS} ${CL_HEADERS} ${LIBFT}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}client/ ${CL_OBJS} ${FRAMEWORKS} -o client
					@echo "\033[0;32m [${NAME}] : ✔️ Successfully built executable\033[1;36m ${NAME} client\033[0;32m for \033[1;36m${UNAME} !\033[0;00m"

server			:	${SV_OBJS} ${HEADERS} ${LIBFT}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}server/ ${SV_OBJS} ${FRAMEWORKS} -o server
					@echo "\033[0;32m [${NAME}] : ✔️ Successfully built executable\033[1;36m ${NAME} server\033[0;32m for \033[1;36m${UNAME} !\033[0;00m"

# ---- Lib rules ---- #

${LIBFT}		:
					make -C libft
					@echo "\033[0;32m [${NAME}/libft] : ✔️ Successfully built libft\033[1;36m ${@} !\033[0;32m"



# ---- Client Compiled Rules ---- #

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

${CL_OBJS}		:	| ${DIR_OBJS}client

${DIR_OBJS}client/%.o	:	${DIR_SRCS}client/%.c ${CL_HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}client/ -c $< -o $@

${DIR_OBJS}client/		:
					${MKDIR} ${DIR_OBJS}client/
					@echo "\033[0;32m [${NAME}/bin/client] : ✔️ Successfully created bin directory\033[1;36m ${DIR_OBJS} !\033[0;00m"

# ---- Server Compiled Rules ---- #

${SV_OBJS}		:	| ${DIR_OBJS}server

${DIR_OBJS}server/%.o	:	${DIR_SRCS}server/%.c ${SV_HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS}server/ -c $< -o $@

${DIR_OBJS}server/		:
					${MKDIR} ${DIR_OBJS}server/
					@echo "\033[0;32m [${NAME}/bin/server] : ✔️ Successfully created bin directory\033[1;36m ${DIR_OBJS} !\033[0;00m"

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}
					@echo "\033[0;31m [${NAME}/bin] : ✔️ Successfully cleaned bin directories\033[1;36m bin/ !\033[0;00m"

fclean			:	clean
					${RM} client server
					@echo "\033[0;31m [${NAME}] : ✔️ Successfully deleted executables!\033[0;00m"

re				:	fclean all

.PHONY:	all clean fclean re
.SILENT:
