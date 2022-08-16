CC = g++
OBJ_FLAGS = -c
FLAGS = -lm -o
NAME = test_generator

all: $(NAME) clean

$(NAME): test_gen.o kvadr_func.o
	$(CC) test_gen.o kvadr_func.o $(FLAGS) $(NAME)

test_gen.o:
	$(CC) $(OBJ_FLAGS) ./source/test_gen.c
kvadr_func.o:
	$(CC) $(OBJ_FLAGS) ../kvadratka/source/kvadr_func.c
clean:
	rm -rf *.o