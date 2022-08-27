CC = g++
OBJ_FLAGS = -c
FLAGS = -o
NAME = str_functions

all: $(NAME) clean
	
$(NAME): main.o functions.o
	$(CC) *.o $(FLAGS) $(NAME)

main.o:
	$(CC) $(OBJ_FLAGS) ./source/main.cpp

functions.o:
	$(CC) $(OBJ_FLAGS) ./source/functions.cpp

clean:
	rm -rf *.o