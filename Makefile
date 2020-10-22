##
## Makefile for BSQ_JPO in /home/leandre/BSQ_JPO
##
## Made by Léandre Blanchard
## Login   <leandre.blanchard@epitech.eu>
##
## Started on  Thu Dec 15 20:24:11 2016 Léandre Blanchard
## Last update Sat Jan  6 19:05:29 2018 Léandre Blanchard
##

NAME	= bsq

CC		= gcc

SRCS	= 	src/main.c
SRCS	+=	src/argument_handlers.c
SRCS	+=	src/load_map.c
SRCS	+=	src/utils.c
SRCS	+=	src/display_map.c
SRCS	+=	src/run_through.c
SRCS	+=	src/square_size.c

OBJ	= $(SRCS:.c=.o)

RM	= rm -f

EXTERNALS = ./lvector ./arguments-handler
LDLIBS += -llargs

EXTERNAL_INCLUDES = $(foreach dir,$(EXTERNALS), -I $(dir))

CFLAGS	= -I ./include $(EXTERNAL_INCLUDES) -Wextra -Wall -std=gnu11

GREEN		= '\033[0;32m'
NO_COLOR	= '\033[0m'

%.o : %.c
	@$ $(CC) $(CFLAGS) -c $< $(LDLIBS) -o $@
	@echo "$(CC) $(CFLAGS) -c $< $(LDLIBS) -o $@ ["$(GREEN)"OK"$(NO_COLOR)"]"
.SUFFIXES: .o .c


all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C arguments-handler
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS)

debug: CFLAGS += -g3 -fsanitize=address
debug: LDLIBS += -lasan
debug:	re

opti: CFLAGS += -Ofast
opti:	re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
