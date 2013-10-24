
#include <iostream>
#include "FindDMP_tests.h"

using namespace std;

//FIND DMP FROM CARTO VIDE
bool FindDMP_tests::findDMPFromCartoVide(){
	Cartography c;
	float fX;
	float fY;

	long int firstPos = 0;
	firstPos = c.FindDMP("SIO2",firstPos ,fX,fY);

	if(firstPos != -1 ){
		cout<<"test failed" << endl;
		return false;
	}else{
		cout<<"test pass" << endl;
		return true;
	}
}
//FIND DMP FROM FAUX NOM
bool FindDMP_tests::findDMPFauxNom(){
	Cartography c;
	float fX = -1;
	float fY = -1;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	c.FindDMP("SsO2",0 ,fX,fY);


	if(fX !=-1 || fY != -1){
		cout<<"test failed" << endl;
		return false;
	}else{
		cout<<"test pass" << endl;
		return true;
	}
}
//FIND DMP NORMAL
bool FindDMP_tests::findDMPNormal(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",0 ,fX,fY);

	if(fX==2 && fY==3 && pos==0){
		cout<<"test pass" << endl;
		return true;
	}else{
		cout<<"test failed" << endl;
		return false;
	}
}
bool FindDMP_tests::findDMPNormal2(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",1 ,fX,fY);

	if(fX==20 && fY==23 && pos==1){
		cout<<"test pass" << endl;
		return true;
	}else{
		cout<<"test failed" << endl;
		return false;
	}
}


bool FindDMP_tests::findDMPNormal3(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",2 ,fX,fY);

	if(fX==24 && fY==-3 && pos == 2){
		cout<<"test pass" << endl;
		return true;
	}else{
		cout<<"test failed" << endl;
		return false;
	}
}

bool FindDMP_tests::findDMPNormal4(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",3 ,fX,fY);

	if(pos == -1){
		cout<<"test pass" << endl;
		return true;
	}else{
		cout<<"test failed" << endl;
		return false;
	}
}


bool FindDMP_tests::findDMPNormal5(){
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
		cout<<"test pass" << endl;
		return true;
	}else{
		cout<<"test failed" << endl;
		return false;
	}
}


bool FindDMP_tests::findDMPFaux6(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIo2",0,fX,fY);

	if(pos == -1){
		cout<<"test pass" << endl;
		return true;
	}else{
		cout<<"test failed" << endl;
		return false;
	}
}


//FIND DMP NORMAL AVEC chiffre ngeatifs
