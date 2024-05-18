CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -Iinc
SRC			=	./src/main.cpp ./src/Phonebook.cpp ./src/Contact.cpp
OBJ			=	$(SRC:.cpp=.o)
NAME		=	phonebook
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
