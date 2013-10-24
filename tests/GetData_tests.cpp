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

bool GetDataTest0 (){
	//Get Data de cartographie : Cas normal.
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


bool GetDataTest1(){
	//Get Data a partir d'une Cartography non remplie
	Cartography c;
	if(c.GetData(20,30)){
		cout<<"GetDataTest1 fail" << endl;
		return false;
	}

	cout<<"GetDataTest1 pass" << endl;
	return true;
}

bool GetDataTest2(){
	//Get data d'une data non existante
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
		cout<<"GetDataTest2 fail" << endl;
		return false;
	}
	cout<<"GetDataTest2 pass" << endl;
	return true;

}

/*
int main(){
	GetDataTest0();
	GetDataTest1();
	GetDataTest2();
}
*/
