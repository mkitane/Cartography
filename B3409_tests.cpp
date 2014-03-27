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
#include "B3409_class.h"
using namespace std;



bool test1() {
	//Test de Count avec une cartography vide.
	Cartography unecarte;
	if(unecarte.Count() == 0) {
		cout << "TestCount" << endl;
		return true;
	}
	cout << "TestCount 1 failed" << endl;
	return false;
}

bool test2() {
	//Test de Count en conditions normales
	Cartography unecarte;
	unecarte.Add(20,12,"Test");
	unecarte.Add(21,12,"Test");
	unecarte.Add(22,12,"Test");
	unecarte.Add(23,12,"Test");
	unecarte.Add(24,12,"Test");
	unecarte.Add(25,12,"Test");
	if(unecarte.Count() == 6) {
		cout << "TestCount 2 pass" << endl;
		return true;
	}
	cout << "TestCount 2 failed" << endl;
	return false;
}

bool test3() {
	//Test de Count avec 1 million delements ajoutes tous differents.
	cout << "TestCount 3 started" << endl;
	Cartography unecarte;
	int x=1;
	int y=1;
	for(int i=0; i<10000; i++) {
		unecarte.Add(x,y,"Test");
		x++;
		y++;
		//if(i%10000==0)
		//cout<<i<<endl;
	}
	//cout << "carte creee" << endl;
	if(unecarte.Count() == 10000) {
		cout << "TestCount 3 pass" << endl;
		return true;
	}
	cout << "TestCount 3 failed" << endl;
	return false;
}

bool test4() {
	//Test de Count avec parametre sur une cartography vide
	Cartography unecarte;
	if(unecarte.Count("test") == 0) {
		cout << "TestCount 4 pass" << endl;
		return true;
	}
	cout << "TestCount 4 failed" << endl;
	return false;
}

bool test5() {
	//Test de sensibilite a la casse.
	Cartography unecarte;
	unecarte.Add(20,12,"Test");
	unecarte.Add(21,12,"Test");
	unecarte.Add(22,12,"Test");
	unecarte.Add(23,12,"Test");

	if(unecarte.Count("test") == 0) {
		cout << "TestCount 5 pass" << endl;
		return true;
	}
	cout << "TestCount 5 failed" << endl;
	return false;
}

bool test6() {
	//Test de Count avec parametre chaine vide.
	Cartography unecarte;
	unecarte.Add(20,12,"Test");
	unecarte.Add(21,12,"Test");
	unecarte.Add(22,12,"Test");
	unecarte.Add(23,12,"Test");
	unecarte.Add(24,12,"Test");
	unecarte.Add(25,12,"Test");
	if(unecarte.Count("") == 0) {
		cout << "TestCount 6 pass" << endl;
		return true;
	}
	cout << "TestCount 6 failed" << endl;
	return false;
}

bool test7() {
	//Test de Count avec parametre - Test Normal
	Cartography unecarte;
	unecarte.Add(0,1,"SiO2");
	unecarte.Add(2,1,"SiO2");
	unecarte.Add(2,5,"O2");
	unecarte.Add(5,3,"SiO2");
	if(unecarte.Count("SiO2") == 3) {
		cout << "TestCount 7 pass" << endl;
		return true;
	}
	cout << "TestCount 7 failed" << endl;
	return false;
}

bool test8() {
	//T-8Ê: Test de sensibilitŽ ˆ la casse 2
	Cartography unecarte;
	for(int i=0; i<100000; i++) {
		if(i%2==0) {
			unecarte.Add(i,-i,"O2");
		}
		else {
			unecarte.Add(i,-i,"o2");
		}
	}
	if(unecarte.Count("O2") == 50000) {
		cout << "TestCount 8 pass" << endl;
		return true;
	}
	cout << "TestCount 8 failed" << endl;
	cout << unecarte.Count("O2") << endl;
	return false;
}



bool test8(int nbElements){
	Cartography c;
	int x=1;
	int y=1;

	float fX ;
	float fY;
	for(int i=0; i<nbElements; i++) {
		c.Add(x,y,"Test");
		x++;
		y++;
		//if(i%10000==0)
		//cout<<i<<endl;
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
	cout << "Difference en secondes pour nbElements :" << nbElements<< "du test1: " <<diff << endl;

	t1 = clock();
	c.FindDMP("Test3",0, fX, fY);
	t2 = clock();
	diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;
	cout << "Difference en secondes pour nbElements :" << nbElements<< "du test1: " <<diff << endl;

	cout << "Test 3 ENDED--------------------pourNBElements :"<<nbElements << endl;

	return true;



}


int main() {

	test1();
	test2();
	test4();
	test5();
	test6();
	test7();
	test8();

	test3();

	return 0;
}