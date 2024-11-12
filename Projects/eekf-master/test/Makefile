OBJS	= test.o
SOURCE	= test.c
HEADER	= 
OUT	= teste.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= gcc

all:	teste.exe

teste.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

test.o: test.c
	$(CC) $(FLAGS) test.c 

clean:
	rm -f $(OBJS) $(OUT)