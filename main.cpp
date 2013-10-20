/*************************************************************************
                           main  -  description
                             -------------------
    début                : 18 oct. 2013
    copyright            : (C) 2013 par kbenhmida
*************************************************************************/

//---------- Réalisation de la classe <main> (fichier main.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include "Cartography.h"
#include "B3409_tests.h"




int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << 2 << endl;

/*
	Cartography *macarte = new Cartography();
	macarte->Add(20,12,"Test");
	macarte->Add(21,12,"Test");
	macarte->Add(22,12,"Test");
	macarte->Add(23,12,"Test");
	macarte->Add(24,12,"Test");
	macarte->Add(25,12,"Test");
	cout << "Ma cartography count : " << macarte->Count() << endl;

	delete macarte;
*/


	Cartography macarte;
	macarte.Add(20,12,"Test");
	macarte.Add(21,12,"Test");
	macarte.Add(202,12,"Test");
	macarte.Add(205,12,"Test");
	cout << "Ma cartography count : " << macarte.Count() << endl;

	B3409_tests test;
	test.test1();
	test.test2();
	test.test3();
	test.test4();
	test.test5();
	test.test6();
	test.test7();

	return 0;
}
