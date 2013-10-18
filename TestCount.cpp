#include "TestCount.h"

TestCount::TestCount()
{
}

TestCount::~TestCount()
{
}

// O veut dire faux, 1 vrai.

bool TestCount::test1() {
	Cartography macarte;
	if(macarte.Count() == 0) {
		return 1;
	}
	return 0;
}

bool TestCount::test2() {
	Cartography macarte;
	macarte.Add(20,12,"Test");
	macarte.Add(21,12,"Test");
	macarte.Add(22,12,"Test");
	macarte.Add(23,12,"Test");
	macarte.Add(24,12,"Test");
	macarte.Add(25,12,"Test");
	if(macarte.Count() == 6) {
		return 1;
	}
	return 0;
}
bool TestCount::test3() {
	Cartography macarte;
	int x=1;
	int y=1;
	for(int i=0; i<1000000; i++) {
		macarte.Add(x,y,"Test");
		x++;
		y++;
	}
	if(macarte.Count() == 1000000) {
		return 1;
	}
	return 0;
}

bool TestCount::test4() {
	Cartography macarte;
	if(macarte.Count("test") == 0) {
		return 1;
	}
	return 0;
}

bool TestCount::test5() {
	Cartography macarte;
	macarte.Add(20,12,"Test");
	macarte.Add(21,12,"Test");
	macarte.Add(22,12,"Test");
	macarte.Add(23,12,"Test");
	macarte.Add(24,12,"Test");
	macarte.Add(25,12,"Test");
	if(macarte.Count("") == 0) {
		return 1;
	}
	return 0;
}

bool TestCount::test6() {
	Cartography macarte;
	macarte.Add(0,1,"SiO2");
	macarte.Add(2,1,"SiO2");
	macarte.Add(2,5,"O2");
	macarte.Add(5,3,"SiO2");
	if(macarte.Count("SiO2") == 3) {
		return 1;
	}
}

bool TestCount::test7() {
	Cartography macarte;
	macarte.Add(0,1,"siO2");
	macarte.Add(2,1,"SIO2");
	macarte.Add(2,5,"SiO2");
	macarte.Add(5,3,"Sio2");
	macarte.Add(5,3,"sio2");
	macarte.Add(5,3,"siO2");
	macarte.Add(5,3,"SIO2");
	macarte.Add(5,3,"SiO2");
	if(macarte.Count("SiO2") == 2) {
		return 1;
	}
	return 0;
}
