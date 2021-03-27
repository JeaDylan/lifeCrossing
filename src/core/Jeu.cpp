#include "Jeu.h"

Jeu::Jeu() : ter(), perso(), jardin() {
         jardin.tabJardin->push_back(Jardin(1,12));//tabJardin[0]
         jardin.tabJardin->push_back(Jardin(3,12));//tabJardin[1]
         jardin.tabJardin->push_back(Jardin(5,12));//tabJardin[2]

         ter.banqueDeTerrain();

         ter.tabTerrain[1].setChar(1,12,'J');
         ter.tabTerrain[1].setChar(3,12,'J');
         ter.tabTerrain[1].setChar(5,12,'J');

        // ter.setChar(12,20,'M');

        // mission.banqueMission(); //initialise les deux missions

 }

EnsembleTerrain& Jeu::getTerrain(){ return ter; }

Personnage& Jeu::getPersonnage(){ return perso; }

EnsembleJardin& Jeu::getJardin(){ return jardin; }

const EnsembleTerrain& Jeu::getConstTerrain()const{ return ter; }

const Personnage& Jeu::getConstPersonnage()const{ return perso; }

const EnsembleJardin& Jeu::getConstJardin()const{ return jardin;  }






void Jeu::actionClavier(const char touche){
string rep;
    switch(touche){
        case 'g' :
			perso.gauche(ter.tabTerrain[1]);
			break;
		case 'd' :
			perso.droite(ter.tabTerrain[1]);
			break;
		case 'h' :
			perso.haut(ter.tabTerrain[1]);
			break;
		case 'b' :
			perso.bas(ter.tabTerrain[1]);
			break;
        case 'p' : //planter
          
            cout<<"Voulez-vous planter une graine? (oui/non) "<<endl;
            cin>>rep;
            assert(rep == "oui" || rep == "non");
            if(rep == "oui"){
                string graine;
                cout<<"Que voulez-vous planter?"<<endl;
                cin>>graine;
                cout<<"La graine est plantée, attendre qu'elle soit recoltable..."<<endl;
                //assert position valide -> fonction
                //assert getOccupe == false -> fonction
                if (planter(graine,perso.getPosX(),perso.getPosY()) == true ){
                    ter.tabTerrain[1].setChar(perso.getPosX(),perso.getPosY(),'-');                
                }                
            }
            break;
        case 'r' : //recolter
            string rep2;
            cout<<"Voulez-vous récolter cette graine (oui/non)?"<<endl;
            cin>>rep2;
            assert(rep2 == "oui" || rep2 == "non");
            if(rep2 == "oui"){
                if(jardin.estRecoltable(perso.getPosX(),perso.getPosY()) == true){
                //assert position valide
                  recolter();
                  ter.tabTerrain[1].setChar(perso.getPosX(),perso.getPosY(),'o');
                }
                
                cout<<"La graine a été placée dans votre inventaire"<<endl;
            }
            else {
                cout << "La graine n'est pas prête...Attendez un peu!" <<endl;
            }
            break;

     /*   case 'm' : //declencher mission     
            string rep3;
            int nuM;
            cout << "Voulez-vous démarrer une mission? (oui/non)" <<endl;
            cin >> rep3;
             assert(rep2 == "oui" || rep2 == "non");
            if(rep3 == "oui"){
                cout << "Laquelle? (1/2)" <<endl;
                cin > nuM;
                if(nuM == 1)
                    mission_1();
                if(nuM == 2)
                    mission_2();
            */
    }
        
}





bool Jeu::planter(string nom, unsigned int nx, unsigned int ny){
    //enlever la graine de l'inventaire du perso
    int i = jardin.recupIndice(nx,ny);
    jardin.assignerFruitLeg(nom,i);
    jardin.tabJardin->at(i).setOccupe(true);    
    clock_t time_req;
    time_req = clock();
    while( (clock() - time_req) < jardin.tabJardin->at(i).getPlant().getTempsRecolte() ){
             sleep(1);
    }
   
    assert(jardin.tabJardin->at(i).getPret() == false);
    jardin.tabJardin->at(i).setPret(true);
    return true;

}



void Jeu::recolter(){
    int i = jardin.recupIndice(perso.getPosX(),perso.getPosY());
    string recolte = jardin.tabJardin->at(i).getPlant().getNomGraine();
    FruitLegume fruitLeg = jardin.banqueFruitLeg.chercherFruitLeg(recolte);
    //ajout fruitLeg à l'inventaire du perso
    jardin.tabJardin->at(i).setOccupe(false); 
    jardin.tabJardin->at(i).setPret(false); 
    FruitLegume vide; 
    jardin.tabJardin->at(i).getPlant() = vide; //on enleve la graine du jardin

        
}


/*bool Jeu::mission_1(){
   //gagner 20 points de vie en mangeant des fruits ou legumes
  
   mission.ajouterMission(mission1); // mission[0] = mission1
   assert(mission.tabMission->size() == 1 );
   // Vie pdv_debut;
   //pdv_debut.setPdv(vie.getPdv()); //on enregistre les pdv de depart
   while(vie.getPdv() != pdv_debut.getPdv() + 20){
          sleep(1);
   }
   assert(vie.getPdv() >= pdv_debut + 20 );      
   mission1.setFini(true);
   cout << "mission terminée! +25$ "<< endl;
   gainArgent(25); //+25$
   return true;

}*/


/*bool Jeu::mission_2(){
    //planter deux graines
   
    
    assert(mission.tabMission->size() == 2 );
    int taille = jardin.tabJardin->size(); 
    do{
        int compteur = 0;
        for(int i=0; i<taille;i++){
            if(jardin.(*tabJardin)[i].plant.getOccupe() == true){//boucle qui compte le nb de parcelle occupé => nb graine plantée
                count += 1;
            }
        }
    assert(jardin.tabJardin->size() >= 2);

    }while(count < 2);
    return true;

}*/


void Jeu::testRegression(){

    cout<<"Debut test regression Module Jeu..."<< endl;
    assert(jardin.tabJardin->at(0).getPosX() == 1);
    assert(jardin.tabJardin->at(0).getPosY() == 12);
    cout <<"Jardin 1 initialisée...OK" <<endl;
    assert(jardin.tabJardin->at(1).getPosX() == 3);
    assert(jardin.tabJardin->at(1).getPosY() == 12);
    cout <<"Jardin 2 initialisée...OK" <<endl;
    assert(ter.tabTerrain[1].getXY(1,12) == 'J');
    assert(ter.tabTerrain[1].getXY(3,12) == 'J');
    assert(ter.tabTerrain[1].getXY(5,12) == 'J');
    cout <<"Le caractere J est placé...OK"<<endl;   
    perso.setPosX(20);
    perso.setPosY(10);
    unsigned int position_depart = perso.getPosX();
    actionClavier('g'); //deplace a gauche
    assert(perso.getPosX() == position_depart - 1 );
    
    actionClavier('p');
    cout<<"Perso deplacé vers la gauche...OK"<<endl;



}