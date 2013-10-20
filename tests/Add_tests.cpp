#include "Add_tests.h"


Add_tests::Add_tests()
{
}

Add_tests::~Add_tests()
{
}

// Teste la vérification des doublons
bool Add_tests::test1() {
	Cartography unecarte;
	unecarte.Add(0,1,"SiO2");
	if(!unecarte.Add(0,1,"O2")) {
		cout << "Test 1 pass" << endl;
		return true;
	}
	cout << "Test 1 failed" << endl;
	return false;
}

// Teste la limite d'ajout d'1 million
bool Add_tests::test2() {
	cout << "Test 2 started" << endl;
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
		cout << "Test 2 pass" << endl;
		return true;
	}
	cout << "Test 2 failed" << endl;
	return false;
}