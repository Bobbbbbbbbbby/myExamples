CC = gcc
SRC = example.c
NAME = example
TAG = -lpthread -g -o
TAG1 = -D EASY
TAG2 = -D PETERSON
TAG3 = -D PASS_PARAMETER

easy: example.c
	@$(CC) $(SRC) $(TAG1) $(TAG) $(NAME)

peterson: example.c
	@echo "peterson algorithm is modified with __sync_synchronize()"
	@$(CC) $(SRC) $(TAG2) $(TAG) $(NAME)

pass_parameter: example.c
	@$(CC) $(SRC) $(TAG3) $(TAG) $(NAME)

clean:
	@rm $(NAME)

.PHONY:clean