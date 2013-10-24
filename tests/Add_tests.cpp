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




bool AddTest0(){
	//Test en conditions normales
	Cartography unecarte;
	for(int i=0;i<50;i++){
		unecarte.Add(i,i,"test");
	}
	unecarte.Display();

	return true;
}
bool AddTest1(){
	//Test en conditions normales avec valeurs aleatoires
	Cartography unecarte;
	for(int i=0;i<50;i++){
		unecarte.Add(rand()%500,-rand()%500,"test");
	}
	unecarte.Display();

	return true;
}
bool AddTest2() {
	// Teste la vŽrification des doublons
	Cartography unecarte;
	unecarte.Add(0,1,"SiO2");
	if(!unecarte.Add(0,1,"O2")) {
		cout << "AddTest 2 pass" << endl;
		return true;
	}
	cout << "AddTest 2 failed" << endl;
	return false;
}

bool AddTest3() {
	// Teste la limite d'ajout d'1 million
	cout << "Test 3 started" << endl;
	Cartography uneeecarte;
	int x=1;
	int y=1;
	for(int i=0; i<1000000; i++) {
		uneeecarte.Add(x,y,"Test");
		x++;
		y++;
		if(i%10000==0)
		cout<<i<<endl;
	}
	// On tente d'ajouter le 1000001 eme point
	if(!uneeecarte.Add(1,20, "Si02")) {
		cout << "AddTest 3 pass" << endl;
		return true;
	}
	cout << "AddTest 3 failed" << endl;
	return false;
}

/*
int main(){
	AddTest0();
	AddTest1();
	AddTest2();
	//AddTest3();
}
*/
