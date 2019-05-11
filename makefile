CC = g++
CFLAGS = -std=c++11

all:NeuralNetwork

NeuralNetwork:main.o 
	$(CC) $(CFLAGS) main.o -o output
main.o:main.cpp
	$(CC) $(CFLAGS) -c main.cpp  

clean:
	rm *.o
