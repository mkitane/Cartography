/*************************************************************************
                           B3409_tests  -  description
                             -------------------
    debut                : 22 oct. 2013
    copyright            : (C) 2013 par mkitane
*************************************************************************/


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <iostream>
//------------------------------------------------------ Include personnel
#include "../B3409_class.h"
using namespace std;



bool testf1() {
	//ajouter puis compter les differents cas
    Cartography unecarte;
    unecarte.Add(20,12,"Si02");
    unecarte.Add(21,12,"02");
    unecarte.Add(22,12,"si02");
    unecarte.Add(23,12,"SI02");
    unecarte.Add(24,12,"o2");
    unecarte.Add(25,12,"Test");
    
    if(unecarte.Count("test") == 0 && unecarte.Count("Test") == 1 && unecarte.Count() == 6) {
        cout << "Testf1 pass" << endl;
        return true;
    }
    return false;
}

bool testf2() {
	//Creer /ajouter puis afficher
    Cartography unecarte;
    unecarte.Add(20,12,"Si02");
    unecarte.Add(21,12,"02");
    unecarte.Add(22,12,"si02");
    unecarte.Add(23,12,"SI02");
    unecarte.Add(24,12,"o2");
    unecarte.Add(25,12,"Test");

    unecarte.Display();
    
    return true;
}


bool testf3() {
	//Creer plein de points et les ajouter puis afficher et en chercher quelques uns
    Cartography unecarte;
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

    float fX;
    float fY;

    if(unecarte.FindDMP("SIO2",0,fX,fY) == 3 && unecarte.FindDMP("SIO2",4,fX,fY) == 9) {
        cout << "Testf3 pass" << endl;
    	return true;
    }
    cout << "Testf3 fail" << endl;
    return false;
}

bool testf4() {
	//Creer cartographie vide et essayer de count et chercher.
    Cartography unecarte;

    float fX;
    float fY;

    if(unecarte.Count() == 0 && unecarte.FindDMP("SiO2",0,fX,fY) == -1) {
        cout << "Testf4 pass" << endl;
    	return true;
    }
    cout << "Testf4 fail" << endl;
    return false;
}

bool testf5() {
	//Creer cartographie la remplir puis chercher dedans puis lancer count
    Cartography unecarte;
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

    float fX;
    float fY;

    if(unecarte.Count() == 11 && unecarte.FindDMP("SiO2",0,fX,fY) == 0) {
        cout << "Testf5 pass" << endl;
    	return true;
    }

    cout << "Testf5 fail" << endl;
    return false;
}

bool testf6(int nbElements){
	//Test Qui permet devaluer les performances de la methode FINDDMP
	//en fonction du nombre Delements sur lesquels il doit rechercher
	//et passe en parametre
	cout << "Test 6 started--------------------pourNBElements :"<<nbElements << endl;
	Cartography c;
	int x=1;
	int y=1;

	float fX ;
	float fY;
	for(int i=0; i<nbElements; i++) {
		c.Add(x,y,"Test");
		x++;
		y++;
	}
	c.Add(x,y,"Test1");
	x++;
	y++;
	c.Add(x,y,"Test1");
	x++;
	y++;


	clock_t t1, t2;
	t1 = clock();
	c.FindDMP("Test1",0, fX, fY);
	t2 = clock();
	float diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
	cout << "Difference en secondes pour nbElements :" << nbElements<< "du Test1: " <<diff << endl;

	t1 = clock();
	c.FindDMP("Test3",0, fX, fY);
	t2 = clock();
	diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
	cout << "Difference en secondes pour nbElements :" << nbElements<< "du Test3: " <<diff << endl;

	cout << "Test 6 ENDED--------------------pourNBElements :"<<nbElements << endl;

	return true;
}
/*
int main(){
	testf1();
	testf2();
	testf3();
	testf4();
	testf5();

	testf6(50000);
	testf6(100000);
	testf6(1000);
}
*/
