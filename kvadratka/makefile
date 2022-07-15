CC = gcc
OBJ_FLAGS = -lm -c
FLAGS = -lm -o
NAME = kvadratka

all: $(NAME) clean

$(NAME): main.o kvadr_func.o test.o
	$(CC) main.o kvadr_func.o test.o $(FLAGS) $(NAME)

main.o:
	$(CC) $(OBJ_FLAGS) ./source/main.c

kvadr_func.o:
	$(CC) $(OBJ_FLAGS) ./source/kvadr_func.c

test.o:
	$(CC) $(OBJ_FLAGS) ./source/test.c 
clean:
	rm -rf *.o