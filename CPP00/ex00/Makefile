NAME = megaphone

SRCS = megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
