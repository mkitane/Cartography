#include "Add_tests.h"


//Test en conditions normales
bool Add_tests::test0(){
	Cartography unecarte;
	for(int i=0;i<50;i++){
		unecarte.Add(i,i,"test");
	}
	unecarte.Display();

	return true;
}
bool Add_tests::test0b(){
	Cartography unecarte;
	for(int i=0;i<50;i++){
		unecarte.Add(rand()%100000,rand()%100000,"test");
	}
	unecarte.Display();

	return true;
}
// Teste la vŽrification des doublons
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




bool getData (){
	Cartography c;

	c.Add(1,2,"a");
	c.Add(3,20,"b");
	c.Add(71,62,"c");
	c.Add(1,62,"a");
	c.Add(-12,243,"b");
	c.Add(12,-243,"c");
	c.Add(12,-243,"d");
	c.Add(-12,243,"e");

	cout<<c.GetData(1,2)<<endl;
	cout<<c.GetData(3,20)<<endl;
	cout<<c.GetData(-12,243)<<endl;
	cout<<c.GetData(12,-243)<<endl;
	cout<<c.GetData(1,2)<<endl;

	return true;
}

bool getDataFromCartoNull(){
	Cartography c;
	if(c.GetData(20,30)){
		return false;
	}

	return true;
}
bool getDataNULL(){
	Cartography c;

	c.Add(1,2,"a");
	c.Add(3,20,"b");
	c.Add(71,62,"c");
	c.Add(1,62,"a");
	c.Add(-12,243,"b");
	c.Add(12,-243,"c");
	c.Add(12,-243,"d");
	c.Add(-12,243,"e");

	if(c.GetData(20,30)){
		return false;
	}

	return true;

}
