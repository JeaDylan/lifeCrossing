# p1808182_p1801630_p1805736_projet

Mini jeu appelé “Life crossing” qui simule le concept de vie artificielle, ce jeu s’apparente au Sims.

## Explication détaillée

### Commande de compilation
S'assurer que la lib SDL est installée (sudo apt-get install libsdl1.2-dev libsdl-image1.2-dev)
En tapant 'make' dans le terminal.

### Commandes d'execution
- **./bin/test** : Executable qui fait un test de régression pour tout les modules.
- **./bin/jeu_sdl** : Il lance le jeu en mode graphique. A executer avec un serveur X ouvert. (sinon "Segmentation fault (core dumped)").
- **./bin/jeu_txt** : Il lance le jeu en mode texte.

### Règles du jeu
Le but du jeu est d’explorer l’univers de “Life crossing’, de ‘survivre', de gagner de l’argent et monter en niveau. Pour se faire, le joueur peut développer son activité de vente de produits dans son jardin par exemple, réaliser des missions rémunérées et faire des activitées.

### Fonctionnalités
1. Le joueur peut se déplacer d'un terrain à un autre.
2. Le joueur peut dormir, manger et boire.
3. Le joueur peut planter des graine et recoleter des fruits et des legumes.
4. Le joueur peut dialoguer avec des PNJ (Personnage Non Joueur).
5. Le joueur peut faire des activités, des missions et acheter des vivres.
6. Le joueur peut vendre les fruits et legumes de son inventaire.

## Organisation des fichiers/répertoires

**p1808182_p1801630_p1805736_projet** 
- **bin** : Contient les executables (ex: './bin/test' -> execute test).
- **data** : Contient les images manipulées et les données chiffrées.
- **doc** : Contient la documentation (html/index.html : page principale), la presentation du projet et ses diagrammes.
- **lib** : Contient les librairies externes nécessaires au jeu.
- **obj** : Contient les fichiers objets à compiler.
- **src/core** : Contient les modules noyeau du jeu.
- **src/sdl** : Contient le programme principale du jeu en mode graphique.
- **src/txt** : Contient le programme principale du jeu en mode texte.
- **Makefile** : Permet de compiler le programme après modification.
- **README.md** : ce readme.

## Contributeurs
Tommy Rahita p1801630
Niniana Rahita p1805736
Dylan Jeannin p1808182

Projet LIFAP4
