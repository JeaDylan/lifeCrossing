EXEC_NAME = ./bin/test
OBJS_TEST = ./obj/maintest.o ./obj/Point2D.o ./obj/FruitLegume.o ./obj/EnsembleFruitLeg.o ./obj/Jardin.o ./obj/Meuble.o ./obj/EnsembleMeuble.o
SRC_FILES = ./src/core/FruitLegume.h ./src/core/Mission.h ./src/core/Point2D.h ./src/core/EnsembleFruitLeg.h ./src/core/Jardin.h ./src/core/Meuble.h ./src/core/EnsembleMeuble.h

CC = g++
CFLAGS = -ggdb -Wall

all: $(EXEC_NAME) ./doc/projet.doxy

./bin/test: $(OBJS_TEST) 
	$(CC) $(OBJS_TEST) -o ./bin/test

./obj/maintest.o: ./src/txt/mainTest.cpp ./src/core/FruitLegume.h ./src/core/EnsembleFruitLeg.h ./src/core/Jardin.h ./src/core/EnsembleMeuble.h
	$(CC) $(CFLAGS) -c ./src/txt/mainTest.cpp -o ./obj/maintest.o

./obj/Point2D.o: ./src/core/Point2D.cpp ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/core/Point2D.cpp -o ./obj/Point2D.o

./obj/FruitLegume.o: ./src/core/FruitLegume.cpp ./src/core/FruitLegume.h
	$(CC) $(CFLAGS) -c ./src/core/FruitLegume.cpp -o ./obj/FruitLegume.o

./obj/EnsembleFruitLeg.o: ./src/core/EnsembleFruitLeg.cpp ./src/core/EnsembleFruitLeg.h ./src/core/FruitLegume.h
	$(CC) $(CFLAGS) -c ./src/core/EnsembleFruitLeg.cpp -o ./obj/EnsembleFruitLeg.o	

./obj/Jardin.o: ./src/core/Jardin.cpp ./src/core/Jardin.h 
	$(CC) $(CFLAGS) -c ./src/core/Jardin.cpp -o ./obj/Jardin.o	

./obj/Meuble.o: ./src/core/Meuble.cpp ./src/core/Meuble.h	
	$(CC) $(CFLAGS) -c ./src/core/Meuble.cpp -o ./obj/Meuble.o

./obj/EnsembleMeuble.o: ./src/core/EnsembleMeuble.cpp ./src/core/EnsembleMeuble.h ./src/core/Meuble.h	
	$(CC) $(CFLAGS) -c ./src/core/EnsembleMeuble.cpp -o ./obj/EnsembleMeuble.o

./doc/projet.doxy: $(SRC_FILES)
	doxygen doc/projet.doxy

clean:
	rm -r ./obj/*.o ./bin/* ./doc/html/ ./doc/latex

veryclean: clean 
	rm -r ./obj/*.o ./bin/* ./doc/html/ ./doc/latex