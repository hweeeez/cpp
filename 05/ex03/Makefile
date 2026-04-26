NAME = Bureaucrat
srcfiles := Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp
objfiles := $(srcfiles:.cpp=.o)
CFLAGS = -g -Wall -Werror -Wextra -std=c++98

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