#include <iostream>
#include "TestCount.h"
using namespace std;

TestCount::TestCount()
{
}

TestCount::~TestCount()
{
}

// 2 veut dire faux, 1 vrai.

bool TestCount::test1() {
	Cartography uneecarte;
	if(uneecarte.Count() == 0) {
		cout << "Test 1 succeeded" << endl;
		return true;
	}
	cout << "Test 1 failed" << endl;
	return false;
}

bool TestCount::test2() {
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
bool TestCount::test3() {
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
	cout << "carte creee" << endl;
	if(uneeecarte.Count() == 1000000) {
		cout << "Test 3 pass" << endl;
		return true;
	}
	cout << "Test 3 failed" << endl;
	return false;
}

bool TestCount::test4() {
	Cartography unecarte;
	if(unecarte.Count("test") == 0) {
		cout << "Test 4 pass" << endl;
		return true;
	}
	cout << "Test 4 failed" << endl;
	return false;
}

bool TestCount::test5() {
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

bool TestCount::test6() {
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

bool TestCount::test7() {
	Cartography unecarte;
	unecarte.Add(0,1,"siO2");
	unecarte.Add(2,1,"SIO2");
	unecarte.Add(2,5,"SiO2");
	unecarte.Add(5,3,"Sio2");
	unecarte.Add(5,5,"sio2");
	unecarte.Add(10,3,"siO2");
	unecarte.Add(7,2,"SIO2");
	unecarte.Add(4,1,"SiO2");
	if(unecarte.Count("SiO2") == 2) {
		cout << "Test 7 pass" << endl;
		return true;
	}
	cout << "Test 7 failed" << endl;
	cout << unecarte.Count("SiO2") << endl;
	return false;
}
