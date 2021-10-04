NAME = zombie_test

SRCS = Zombie.cpp \
	   newZombie.cpp \
	   randomChump.cpp \
	   main.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp %.hpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
