EXEC_NAME = ./bin/test
OBJS_TEST = ./obj/maintest.o ./obj/Point2D.o

CC = g++
CFLAGS = -ggdb -Wall

all: $(EXEC_NAME)

./bin/test: $(OBJS_TEST) 
	$(CC) $(OBJS_TEST) -o ./bin/test

./obj/maintest.o: ./src/txt/mainTest.cpp ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/txt/mainTest.cpp -o ./obj/maintest.o

./obj/Point2D.o: ./src/core/Point2D.cpp ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/core/Point2D.cpp -o ./obj/Point2D.o

./doc/projet.doxy: ./src/*
	doxygen doc/projet.doxy

clean:
	rm ./obj/*.o ./bin/* ./doc/*

veryclean: clean 
	rm ./obj/*.o ./bin/* ./doc/*