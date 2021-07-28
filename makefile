NAME = cat
FLAGS = -g -Wall -pedantic-errors

compile: $(NAME).c
	gcc -o $(NAME) $(FLAGS) $(NAME).c

run: compile
	./$(NAME)

clean:
	rm -f $(NAME)
