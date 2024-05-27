CC = clang

CFLAGS = -O3 -Wall -Wextra -pedantic

OBJS = obj/main.o obj/diningPhilosophers.o

TARGET = dining_philosophers.out

INCLUDES = inc

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

obj/main.o: src/main.c
	$(CC) -c src/main.c -o obj/main.o $(CFLAGS) -I$(INCLUDES)

obj/diningPhilosophers.o: src/diningPhilosophers.c
	$(CC) -c src/diningPhilosophers.c -o obj/diningPhilosophers.o $(CFLAGS) -I$(INCLUDES)


clean:	
	rm  obj/*.o dining_philosophers.out