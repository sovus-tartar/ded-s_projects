CC = g++
OBJ_FLAGS = -lm -c
FLAGS = -lm -o
NAME = kvadratka

all: $(NAME) clean

$(NAME): main.o kvadr_func.o test.o
	$(CC) main.o kvadr_func.o test.o $(FLAGS) $(NAME)

main.o:
	$(CC) $(OBJ_FLAGS) ./source/main.cpp

kvadr_func.o:
	$(CC) $(OBJ_FLAGS) ./source/kvadr_func.cpp

test.o:
	$(CC) $(OBJ_FLAGS) ./source/test.cpp 
clean:
	rm -rf *.o