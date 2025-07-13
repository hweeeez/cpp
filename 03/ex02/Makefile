NAME = ClapTrap
srcfiles := ClapTrap.hpp ClapTrap.cpp main.cpp
objfiles := $(srcfiles:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(objfiles)
	c++ $(CFLAGS) $(objfiles) -o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(objfiles)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re