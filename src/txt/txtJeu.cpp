#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Jeu.h"

void txtAff(WinTXT & win, Jeu & jeu) {
//	const EnsembleTerrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPersonnage();
  //  const EnsembleJardin& jardin = jeu.getConstJardin();

	win.clear();

    // Affichage quartier
    jeu.getTerrain().tabTerrain[1].afficheTerrain();
    
    //Affichage du Personnage
    win.print(perso.getPosX(),perso.getPosY(),'P');

    

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().tabTerrain[1].getdimX(),jeu.getConstTerrain().tabTerrain[1].getdimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		//jeu.actionsAutomatiques();

		c = win.getCh();
		switch (c) {
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;
			case 'o':
				jeu.actionClavier('b');
				break;
            case 'p':
                jeu.actionClavier('p');
			case 'q':
				ok = false;
				break;
		}

	} while (ok);

}
