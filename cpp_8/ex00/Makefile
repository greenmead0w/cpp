CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)
INCLUDES = easyfind.hpp
NAME = easyfind

#explicit rule to use my compiler and flags (if not stated it uses g++)
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all