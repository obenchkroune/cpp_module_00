CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I.
SRC			=	Account.cpp tests.cpp
OBJ			=	$(SRC:.cpp=.o)
NAME		=	account
RM			=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)
