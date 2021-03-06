EXEC_NAME = ./bin/test ./bin/jeu_txt ./bin/jeu_sdl
OBJS_TEST = ./obj/maintest.o ./obj/Point2D.o ./obj/EnsemblePnj.o ./obj/EnsembleActivite.o ./obj/FruitLegume.o ./obj/EnsembleFruitLeg.o ./obj/Jardin.o ./obj/EnsembleJardin.o ./obj/Meuble.o ./obj/EnsembleMeuble.o ./obj/Terrain.o ./obj/EnsembleTerrain.o ./obj/Personnage.o ./obj/Jauge.o ./obj/Pnj.o ./obj/Jeu.o ./obj/Activite.o ./obj/Inventaire.o ./obj/Vie.o ./obj/Portail.o ./obj/EnsemblePortail.o ./obj/Mission.o ./obj/EnsembleMission.o
OBJS_JEU_TXT = ./obj/main_txt.o ./obj/Point2D.o ./obj/FruitLegume.o ./obj/EnsembleFruitLeg.o ./obj/Jardin.o ./obj/EnsembleJardin.o ./obj/Terrain.o  ./obj/EnsembleTerrain.o ./obj/Personnage.o ./obj/Meuble.o ./obj/EnsembleMeuble.o ./obj/Jeu.o ./obj/winTxt.o ./obj/txtJeu.o ./obj/EnsemblePnj.o ./obj/Pnj.o ./obj/EnsembleActivite.o ./obj/Activite.o ./obj/Inventaire.o ./obj/Vie.o ./obj/Jauge.o ./obj/Portail.o ./obj/EnsemblePortail.o ./obj/Mission.o ./obj/EnsembleMission.o
OBJS_JEU_SDL = ./obj/main_sdl.o ./obj/sdlJeu.o  ./obj/Map.o  ./obj/Point2D.o ./obj/EnsemblePnj.o ./obj/EnsembleActivite.o ./obj/FruitLegume.o ./obj/EnsembleFruitLeg.o ./obj/Jardin.o ./obj/EnsembleJardin.o ./obj/Meuble.o ./obj/EnsembleMeuble.o ./obj/Terrain.o ./obj/EnsembleTerrain.o ./obj/Personnage.o ./obj/Jauge.o ./obj/Pnj.o ./obj/Jeu.o ./obj/Activite.o ./obj/Inventaire.o ./obj/Vie.o ./obj/Mission.o  ./obj/EnsembleMission.o ./obj/Portail.o ./obj/EnsemblePortail.o
SRC_FILES = ./src/core/EnsemblePnj.h ./src/core/EnsembleActivite.h ./src/core/FruitLegume.h ./src/core/Point2D.h ./src/core/EnsembleFruitLeg.h ./src/core/Jardin.h ./src/core/EnsembleJardin.h ./src/core/Meuble.h ./src/core/EnsembleMeuble.h ./src/core/Terrain.h ./src/core/EnsembleTerrain.h ./src/core/Personnage.h ./src/core/Jauge.h ./src/core/Pnj.h ./src/core/Mission.h  ./src/core/EnsembleMission.h  ./src/core/Jeu.h ./src/core/Activite.h ./src/core/Inventaire.h ./src/core/Vie.h ./src/core/Portail.h ./src/core/EnsemblePortail.h

CC = g++
CFLAGS = -ggdb -Wall

all: $(EXEC_NAME) ./doc/projet.doxy

./bin/test: $(OBJS_TEST) 
	$(CC) $(OBJS_TEST) -o ./bin/test

./bin/jeu_txt: $(OBJS_JEU_TXT) 
	$(CC) $(OBJS_JEU_TXT) -o ./bin/jeu_txt -lncurses

./bin/jeu_sdl: $(OBJS_JEU_SDL)
	$(CC) $(OBJS_JEU_SDL) -o ./bin/jeu_sdl -lSDL -lSDL_image

./obj/maintest.o: ./src/txt/mainTest.cpp ./src/core/FruitLegume.h ./src/core/EnsembleFruitLeg.h ./src/core/Jardin.h ./src/core/EnsembleMeuble.h ./src/core/EnsembleMeuble.h  ./src/core/EnsembleMission.h ./src/core/EnsemblePortail.h ./src/core/Jeu.h ./src/core/Personnage.h ./src/core/Activite.h ./src/core/Jauge.h ./src/core/Inventaire.h ./src/core/Portail.h
	$(CC) $(CFLAGS) -c ./src/txt/mainTest.cpp -o ./obj/maintest.o

./obj/main_txt.o: ./src/txt/main_txt.cpp  ./src/txt/winTxt.h ./src/txt/txtJeu.h ./src/core/EnsembleFruitLeg.h ./src/core/EnsembleJardin.h ./src/core/EnsembleTerrain.h ./src/core/EnsembleMeuble.h  ./src/core/EnsembleMission.h ./src/core/Jeu.h ./src/core/Personnage.h ./src/core/EnsemblePnj.h ./src/core/EnsembleActivite.h 
	$(CC) $(CFLAGS) -c ./src/txt/main_txt.cpp  -o ./obj/main_txt.o

./obj/main_sdl.o: ./src/sdl/main_sdl.cpp ./src/core/Jeu.h  
	$(CC) $(CFLAGS) -c ./src/sdl/main_sdl.cpp -o ./obj/main_sdl.o

./obj/Map.o: ./src/sdl/map.cpp ./src/sdl/map.h
	$(CC) $(CFLAGS) -c ./src/sdl/map.cpp -o ./obj/Map.o

./obj/sdlJeu.o: ./src/sdl/sdlJeu.cpp ./src/sdl/sdlJeu.h ./src/sdl/constantes.h ./src/sdl/map.h
	$(CC) $(CFLAGS) -c ./src/sdl/sdlJeu.cpp -o ./obj/sdlJeu.o

./obj/Point2D.o: ./src/core/Point2D.cpp ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/core/Point2D.cpp -o ./obj/Point2D.o

./obj/FruitLegume.o: ./src/core/FruitLegume.cpp ./src/core/FruitLegume.h
	$(CC) $(CFLAGS) -c ./src/core/FruitLegume.cpp -o ./obj/FruitLegume.o

./obj/EnsembleFruitLeg.o: ./src/core/EnsembleFruitLeg.cpp ./src/core/EnsembleFruitLeg.h ./src/core/FruitLegume.h
	$(CC) $(CFLAGS) -c ./src/core/EnsembleFruitLeg.cpp -o ./obj/EnsembleFruitLeg.o	

./obj/Jardin.o: ./src/core/Jardin.cpp ./src/core/Jardin.h  ./src/core/Point2D.h ./src/core/FruitLegume.h
	$(CC) $(CFLAGS) -c ./src/core/Jardin.cpp -o ./obj/Jardin.o	

./obj/EnsembleJardin.o: ./src/core/EnsembleJardin.cpp ./src/core/EnsembleJardin.h ./src/core/Jardin.h 
	$(CC) $(CFLAGS) -c ./src/core/EnsembleJardin.cpp -o ./obj/EnsembleJardin.o

./obj/Meuble.o: ./src/core/Meuble.cpp ./src/core/Meuble.h	
	$(CC) $(CFLAGS) -c ./src/core/Meuble.cpp -o ./obj/Meuble.o

./obj/EnsembleMeuble.o: ./src/core/EnsembleMeuble.cpp ./src/core/EnsembleMeuble.h ./src/core/Meuble.h	
	$(CC) $(CFLAGS) -c ./src/core/EnsembleMeuble.cpp -o ./obj/EnsembleMeuble.o

./obj/Terrain.o: ./src/core/Terrain.cpp ./src/core/Terrain.h ./src/core/EnsembleMeuble.h ./src/core/EnsemblePortail.h ./src/core/Portail.h ./src/core/Meuble.h
	$(CC) $(CFLAGS) -c ./src/core/Terrain.cpp -o ./obj/Terrain.o

./obj/EnsembleTerrain.o: ./src/core/EnsembleTerrain.cpp ./src/core/EnsembleTerrain.h ./src/core/Terrain.h ./src/core/EnsembleMeuble.h ./src/core/Meuble.h ./src/core/EnsemblePortail.h ./src/core/Portail.h ./src/core/EnsembleJardin.h ./src/core/Jardin.h
	$(CC) $(CFLAGS) -c ./src/core/EnsembleTerrain.cpp -o ./obj/EnsembleTerrain.o

./obj/Vie.o: ./src/core/Vie.cpp ./src/core/Vie.h ./src/core/Jauge.h
	$(CC) $(CFLAGS) -c ./src/core/Vie.cpp -o ./obj/Vie.o

./obj/Personnage.o: ./src/core/Personnage.cpp ./src/core/Personnage.h ./src/core/Terrain.h ./src/core/Point2D.h ./src/core/Vie.h ./src/core/Inventaire.h
	$(CC) $(CFLAGS) -c ./src/core/Personnage.cpp -o ./obj/Personnage.o

./obj/Jauge.o: ./src/core/Jauge.cpp ./src/core/Jauge.h 
	$(CC) $(CFLAGS) -c ./src/core/Jauge.cpp -o ./obj/Jauge.o
	
./obj/Pnj.o: ./src/core/Pnj.cpp ./src/core/Pnj.h ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/core/Pnj.cpp -o ./obj/Pnj.o

./obj/EnsemblePnj.o: ./src/core/EnsemblePnj.cpp ./src/core/EnsemblePnj.h ./src/core/Pnj.h
	$(CC) $(CFLAGS) -c ./src/core/EnsemblePnj.cpp -o ./obj/EnsemblePnj.o

./obj/Activite.o: ./src/core/Activite.cpp ./src/core/Activite.h ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/core/Activite.cpp -o ./obj/Activite.o

./obj/EnsembleActivite.o: ./src/core/EnsembleActivite.cpp ./src/core/EnsembleActivite.h ./src/core/Activite.h
	$(CC) $(CFLAGS) -c ./src/core/EnsembleActivite.cpp -o ./obj/EnsembleActivite.o

./obj/Portail.o: ./src/core/Portail.cpp ./src/core/Portail.h ./src/core/Point2D.h
	$(CC) $(CFLAGS) -c ./src/core/Portail.cpp -o ./obj/Portail.o

./obj/EnsemblePortail.o: ./src/core/EnsemblePortail.cpp ./src/core/EnsemblePortail.h ./src/core/Portail.h
	$(CC) $(CFLAGS) -c ./src/core/EnsemblePortail.cpp -o ./obj/EnsemblePortail.o

./obj/Mission.o: ./src/core/Mission.cpp ./src/core/Mission.h
	$(CC) $(CFLAGS) -c ./src/core/Mission.cpp -o ./obj/Mission.o

./obj/EnsembleMission.o: ./src/core/EnsembleMission.cpp ./src/core/EnsembleMission.h ./src/core/Mission.h
	$(CC) $(CFLAGS) -c ./src/core/EnsembleMission.cpp -o ./obj/EnsembleMission.o

./obj/Inventaire.o: ./src/core/Inventaire.cpp ./src/core/Inventaire.h ./src/core/Jauge.h ./src/core/EnsembleFruitLeg.h
	$(CC) $(CFLAGS) -c ./src/core/Inventaire.cpp -o ./obj/Inventaire.o

./obj/Jeu.o: ./src/core/Jeu.cpp ./src/core/Jeu.h ./src/core/Personnage.h ./src/core/EnsembleTerrain.h ./src/core/EnsembleJardin.h ./src/core/EnsembleMission.h
	$(CC) $(CFLAGS) -c ./src/core/Jeu.cpp -o ./obj/Jeu.o

./obj/txtJeu.o: ./src/txt/txtJeu.cpp  ./src/txt/txtJeu.h ./src/core/Jeu.h ./src/core/Personnage.h ./src/core/EnsembleTerrain.h ./src/core/EnsembleJardin.h 
	$(CC) $(CFLAGS) -c ./src/txt/txtJeu.cpp  -o ./obj/txtJeu.o

./obj/winTxt.o: ./src/txt/winTxt.cpp  ./src/txt/winTxt.h 
	$(CC) $(CFLAGS) -c ./src/txt/winTxt.cpp  -o ./obj/winTxt.o
	
./doc/projet.doxy: $(SRC_FILES)
	doxygen doc/projet.doxy

clean:
	rm -r ./obj/*.o ./bin/* ./doc/html/ ./doc/latex

veryclean: clean 
	rm -r ./obj/*.o ./bin/* ./doc/html/ ./doc/latex
