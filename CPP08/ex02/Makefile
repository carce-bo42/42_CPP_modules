NAME = STL3

SRCS = main.cpp mutantstack.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

MAIN_DEPENDENCIES = mutantstack.hpp

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp $(MAIN_DEPENDENCIES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
