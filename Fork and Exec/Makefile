CC = gcc
SRC1 = fork.c
SRC2 = exec.c
NAME2 = exec
NAME1 = fork
TAG = -g -o

all: fork exec

fork: fork.c
	@$(CC) $(SRC1) $(TAG) $(NAME1)

exec: fork exec.c
	@$(CC) $(SRC2) $(TAG) $(NAME2)

clean:
	@rm $(NAME1) $(NAME2)

.PHONY: clean