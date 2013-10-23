#include "FindDMP_tests.h"

FindDMP_tests::FindDMP_tests()
{
}

FindDMP_tests::~FindDMP_tests()
{
}

//FIND DMP FROM CARTO VIDE
bool findDMPFromCartoVide(){
	Cartography c;
	float fX;
	float fY;

	long int firstPos = 0;
	c.FindDMP("SIO2",firstPos ,fX,fY);

	if(fX || fY){
		return false;
	}else{
		return true;
	}
}
//FIND DMP FROM FAUX NOM
bool findDMPFauxNom(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	c.FindDMP("SsO2",0 ,fX,fY);

	if(fX || fY){
		return false;
	}else{
		return true;
	}
}
//FIND DMP NORMAL
bool findDMPNormal(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",0 ,fX,fY);

	if(fX==2 && fY==3 && pos==0){
		return true;
	}else{
		return false;
	}
}
bool findDMPNormal2(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",1 ,fX,fY);

	if(fX==20 && fY==23 && pos==1){
		return true;
	}else{
		return false;
	}
}


bool findDMPNormal3(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",2 ,fX,fY);

	if(fX==24 && fY==-3 && pos == 2){
		return true;
	}else{
		return false;
	}
}

bool findDMPNormal4(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",3 ,fX,fY);

	if(pos == -1){
		return true;
	}else{
		return false;
	}
}


bool findDMPNormal5(){
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
		return true;
	}else{
		return false;
	}
}


bool findDMPFaux6(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIo2",0,fX,fY);

	if(pos == -1){
		return true;
	}else{
		return false;
	}
}


//FIND DMP NORMAL AVEC chiffre ngeatifs
