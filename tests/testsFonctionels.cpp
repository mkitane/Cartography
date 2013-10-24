/*
 * testsFonctionels.cpp
 *
 *  Created on: 24 oct. 2013
 *      Author: Mehdi
 */
#include "../B3409_class.h"


//ajouter puis compter differents cas
bool testf1() {
    Cartography uneecarte;
    unecarte.Add(20,12,"Si02");
    unecarte.Add(21,12,"02");
    unecarte.Add(22,12,"si02");
    unecarte.Add(23,12,"SI02");
    unecarte.Add(24,12,"o2");
    unecarte.Add(25,12,"Test");
    
    if(unecarte.Count("test") == 0 && unecarte.Count("Test") == 1 && unecarte.Count() == 6) {
        cout << "Test pass" << endl;
        return true;
    }
    return false;
}

//Creer /ajouter puis afficher
bool testf2() {
    Cartography uneecarte;
    unecarte.Add(20,12,"Si02");
    unecarte.Add(21,12,"02");
    unecarte.Add(22,12,"si02");
    unecarte.Add(23,12,"SI02");
    unecarte.Add(24,12,"o2");
    unecarte.Add(25,12,"Test");

    unecarte.Display();
    
    return true;
}

//Creer plein de random samples et les ajouter puis afficher et en chercher klksuns

bool testf3() {
    Cartography uneecarte;
    unecarte.Add(20,-12,"SiO2");
    unecarte.Add(21,-12,"02");
    unecarte.Add(22,12,"siO2");
    unecarte.Add(23,12,"SIO2");
    unecarte.Add(24,12,"o2");
    unecarte.Add(25,12,"Test");
    unecarte.Add(20,-11,"SiO2");
    unecarte.Add(21,11,"h20");
    unecarte.Add(22,-11,"siO2");
    unecarte.Add(23,11,"SIO2");
    unecarte.Add(24,-11,"o2");
    if(unecarte.FindDMP("SIO2",0,fX,fY) == 3 && unecarte.FindDMP("SIO2",4,fX,fY) == 9) {
        return true;
    }
    return false;
}

//Creer carto vide/essayer de count et chercher
bool testf4() {
    Cartography uneecarte;
    if(unecarte.Count() == 0 && unecarte.FindDMP("SiO2",0,fX,fY) == -1) {
        return true;
    }
    return false;
}

//Creer carto la remplir/chercher/count
bool testf5() {
    Cartography uneecarte;
    unecarte.Add(20,-12,"SiO2");
    unecarte.Add(21,-12,"02");
    unecarte.Add(22,12,"siO2");
    unecarte.Add(23,12,"SIO2");
    unecarte.Add(24,12,"o2");
    unecarte.Add(25,12,"Test");
    unecarte.Add(20,-11,"SiO2");
    unecarte.Add(21,11,"h20");
    unecarte.Add(22,-11,"siO2");
    unecarte.Add(23,11,"SIO2");
    unecarte.Add(24,-11,"o2");
    if(unecarte.Count() == 11 && unecarte.FindDMP("SiO2",0,fX,fY) == 0) {
        return true;
    }
    return false;
}
