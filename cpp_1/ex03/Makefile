CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
INCLUDES = HumanA.hpp HumanB.hpp Weapon.hpp
OBJ = $(SRC:.cpp=.o)
NAME = violence

# explicit rule to use my compiler and flags (if not stated it uses g++)
%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDES)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re