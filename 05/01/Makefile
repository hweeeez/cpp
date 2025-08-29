NAME = Bureaucrat
srcfiles := Bureaucrat.cpp main.cpp Form.cpp
objfiles := $(srcfiles:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(objfiles)
	c++ $(CFLAGS) $(objfiles) -MMD -MP -o $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -f $(objfiles)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re