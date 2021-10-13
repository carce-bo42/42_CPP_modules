NAME = Exceptions1

SRCS = main.cpp \
	   Bureaucrat.cpp \

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

# Rule for classes with their respective .hpp file:
%.o: %.cpp %.hpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule for other type of .cpp files:
%.o: %.cpp Makefile
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
