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



bool FindDMPTest0(){
	//Find DMP a partir d'une cartography vide
	Cartography c;
	float fX;
	float fY;

	long int firstPos = 0;
	firstPos = c.FindDMP("SIO2",firstPos ,fX,fY);

	if(firstPos != -1 ){
		cout<<"FINDTest0 fail" << endl;
		return false;
	}else{
		cout<<"FINDTest0 pass" << endl;
		return true;
	}
}
bool FindDMPTest1(){
	//FIND DMP a partir d'un faux pszDMP
	Cartography c;
	float fX = -1;
	float fY = -1;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	c.FindDMP("SsO2",0 ,fX,fY);


	if(fX !=-1 || fY != -1){
		cout<<"FINDTest1 fail" << endl;
		return false;
	}else{
		cout<<"FINDTest1 pass" << endl;
		return true;
	}
}


bool FindDMPTest2(){
	//Verifier si sensible a la casse.
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIo2",0,fX,fY);

	if(pos == -1){
		cout<<"FINDTest2 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest2 fail" << endl;
		return false;
	}
}


bool FindDMPTest3(){
	// Test Normal
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",0 ,fX,fY);

	if(fX==2 && fY==3 && pos==0){
		cout<<"FINDTest3 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest3 fail" << endl;
		return false;
	}
}
bool FindDMPTest4(){
	// Test Normal avec position de depart 1
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",1 ,fX,fY);

	if(fX==20 && fY==23 && pos==1){
		cout<<"FINDTest4 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest4 fail" << endl;
		return false;
	}
}


bool FindDMPTest5(){
	// Test Normal avec position de depart 2
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",2 ,fX,fY);

	if(fX==24 && fY==-3 && pos == 2){
		cout<<"FINDTest5 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest5 fail" << endl;
		return false;
	}
}

bool FindDMPTest6(){
	//Test avec position de depart superieur a la taille du tableau
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",3 ,fX,fY);

	if(pos == -1){
		cout<<"FINDTest6 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest6 fail" << endl;
		return false;
	}
}

bool FindDMPTest7(){
	//Test Normal
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(234,-3,"NA");
	c.Add(24,-53,"NA32");
	c.Add(243,-323,"NA");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",3 ,fX,fY);

	if(pos == 5 && fX == 24 && fY==-3){
		cout<<"FINDTest7 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest7 fail" << endl;
		return false;
	}
}

bool FindDMPTest8(){
	// Test avec 100 000 Žlments

	Cartography c;
	float fX;
	float fY;

	int x=1;
	int y=1;
	for(int i=0; i<100000; i++) {
		c.Add(x,y,"Test");
		x++;
		y++;
		if(i%10000==0)
		cout<<i<<endl;
	}
	c.Add(2,3,"SIO2");

	long pos = c.FindDMP("SIO2",0,fX,fY);

	if(pos == 100000){
		cout<<"FINDTest8 pass" << endl;
		return true;
	}else{
		cout<<"FINDTest8 fail" << endl;
		return false;
	}
}

/*
int main(){
	FindDMPTest0();
	FindDMPTest1();
	FindDMPTest2();
	FindDMPTest3();
	FindDMPTest4();
	FindDMPTest5();
	FindDMPTest6();
	FindDMPTest7();
	FindDMPTest8();
}
*/
