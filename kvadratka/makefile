CC = gcc
OBJ_FLAGS = -lm -c
FLAGS = -lm -o
NAME = kvadratka

all: $(NAME) clean

$(NAME): main.o kvadr_func.o
	$(CC) main.o kvadr_func.o $(FLAGS) $(NAME)

main.o:
	$(CC) $(OBJ_FLAGS) ./source/main.c

kvadr_func.o:
	$(CC) $(OBJ_FLAGS) ./source/kvadr_func.c

clean:
	rm -rf *.o

test:
	gcc ./source/main.c ./source/kvadr_func.c -lm -DTEST -o kvadratka_test
