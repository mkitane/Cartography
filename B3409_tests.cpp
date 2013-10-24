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
	Cartography uneecarte;
	if(uneecarte.Count() == 0) {
		cout << "Test 1 succeeded" << endl;
		return true;
	}
	cout << "Test 1 failed" << endl;
	return false;
}

bool test2() {
	Cartography unecarte;
	unecarte.Add(20,12,"Test");
	unecarte.Add(21,12,"Test");
	unecarte.Add(22,12,"Test");
	unecarte.Add(23,12,"Test");
	unecarte.Add(24,12,"Test");
	unecarte.Add(25,12,"Test");
	if(unecarte.Count() == 6) {
		cout << "Test 2 pass" << endl;
		return true;
	}
	cout << "Test 2 failed" << endl;
	return false;
}

bool test3() {
	cout << "Test 3 started" << endl;
	Cartography uneeecarte;
	int x=1;
	int y=1;
	for(int i=0; i<20000; i++) {
		uneeecarte.Add(x,y,"Test");
		x++;
		y++;
		//if(i%10000==0)
		//cout<<i<<endl;
	}
	//cout << "carte creee" << endl;
	if(uneeecarte.Count() == 1000000) {
		cout << "Test 3 pass" << endl;
		return true;
	}
	cout << "Test 3 failed" << endl;
	return false;
}

bool test4() {
	Cartography unecarte;
	if(unecarte.Count("test") == 0) {
		cout << "Test 4 pass" << endl;
		return true;
	}
	cout << "Test 4 failed" << endl;
	return false;
}

bool test5() {
	Cartography unecarte;
	unecarte.Add(20,12,"Test");
	unecarte.Add(21,12,"Test");
	unecarte.Add(22,12,"Test");
	unecarte.Add(23,12,"Test");

	if(unecarte.Count("test") == 0) {
		cout << "Test 4 pass" << endl;
		return true;
	}
	cout << "Test 4 failed" << endl;
	return false;
}

bool test6() {
	Cartography unecarte;
	unecarte.Add(20,12,"Test");
	unecarte.Add(21,12,"Test");
	unecarte.Add(22,12,"Test");
	unecarte.Add(23,12,"Test");
	unecarte.Add(24,12,"Test");
	unecarte.Add(25,12,"Test");
	if(unecarte.Count("") == 0) {
		cout << "Test 5 pass" << endl;
		return true;
	}
	cout << "Test 5 failed" << endl;
	return false;
}

bool test7() {
	Cartography unecarte;
	unecarte.Add(0,1,"SiO2");
	unecarte.Add(2,1,"SiO2");
	unecarte.Add(2,5,"O2");
	unecarte.Add(5,3,"SiO2");
	if(unecarte.Count("SiO2") == 3) {
		cout << "Test 6 pass" << endl;
		return true;
	}
	cout << "Test 6 failed" << endl;
	return false;
}

bool test8() {
	Cartography unecarte;
	for(int i=0; i<100000; i++) {
		if(i%2=0) {
			unecarte.Add(i,-i,"O2");
		}
		else {
			unecarte.Add(i,-i,"o2");
		}
	}
	if(unecarte.Count("O2") == 50000) {
		cout << "Test 8 pass" << endl;
		return true;
	}
	cout << "Test 8 failed" << endl;
	cout << unecarte.Count("O2") << endl;
	return false;
}


<<<<<<< HEAD
bool test8(int nbElements){
	cout << "Test 3 started--------------------pourNBElements :"<<nbElements << endl;
=======
bool test9(){
	cout << "Test 9 started" << endl;
>>>>>>> 2cd784e... Ajout test unitaire sensibilité à la casse 3
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

/*
int main() {

	test1();
	test2();


	time_t seconds_past_epoch = time(0);
	test3();
	time_t seconds_past_epoch2 = time(0);


	cout << "Difference en secondes" <<seconds_past_epoch2 - seconds_past_epoch << endl;
	test4();
	test5();
	test6();
	test7();

	return 0;
*/

