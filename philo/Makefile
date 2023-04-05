NAME = philo

RM = rm -rf
CC = gcc -g
FLAGS = -Wall -Wextra -Werror

INC = \
			philo.h \

SRCS = \
			Sources/main.c \
			Sources/routine.c \
			Sources/timing.c \
			Sources/free.c \
			Sources/mutex.c \

OBJS = ${SRCS:.c=.o}

all : ${NAME}

$(NAME) : $(OBJS)
		@$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean :
		${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all

%.o: %.c
		${CC} ${FLAGS} -o $@ -c $<
