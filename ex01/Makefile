NAME = PhoneBook
srcfiles := PhoneBook.cpp Contact.cpp
objfiles := $(srcfiles:.cpp=.o)
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(objfiles)
	g++ $(CFLAGS) $(objfiles) -o $(NAME)

%.o: %.c
	g++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(objfiles)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re