
#include <iostream>
#include "../B3409_class.h"
using namespace std;

//FIND DMP FROM CARTO VIDE
bool FindDMPTest0(){
	Cartography c;
	float fX;
	float fY;

	long int firstPos = 0;
	firstPos = c.FindDMP("SIO2",firstPos ,fX,fY);

	if(firstPos != -1 ){
		cout<<"Test0 fail" << endl;
		return false;
	}else{
		cout<<"Test0 pass" << endl;
		return true;
	}
}
//FIND DMP FROM FAUX NOM
bool FindDMPTest1(){
	Cartography c;
	float fX = -1;
	float fY = -1;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	c.FindDMP("SsO2",0 ,fX,fY);


	if(fX !=-1 || fY != -1){
		cout<<"Test1 fail" << endl;
		return false;
	}else{
		cout<<"Test1 pass" << endl;
		return true;
	}
}


//FAUX
bool FindDMPTest2(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIo2",0,fX,fY);

	if(pos == -1){
		cout<<"Test2 pass" << endl;
		return true;
	}else{
		cout<<"Test2 fail" << endl;
		return false;
	}
}


//FIND DMP NORMAL
bool FindDMPTest3(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",0 ,fX,fY);

	if(fX==2 && fY==3 && pos==0){
		cout<<"Test3 pass" << endl;
		return true;
	}else{
		cout<<"Test3 fail" << endl;
		return false;
	}
}
//NORMAL
bool FindDMPTest4(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",1 ,fX,fY);

	if(fX==20 && fY==23 && pos==1){
		cout<<"Test4 pass" << endl;
		return true;
	}else{
		cout<<"Test4 fail" << endl;
		return false;
	}
}


//Normal
bool FindDMPTest5(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",2 ,fX,fY);

	if(fX==24 && fY==-3 && pos == 2){
		cout<<"Test5 pass" << endl;
		return true;
	}else{
		cout<<"Test5 fail" << endl;
		return false;
	}
}

//normal
bool FindDMPTest6(){
	Cartography c;
	float fX;
	float fY;


	c.Add(2,3,"SIO2");
	c.Add(20,23,"SIO2");
	c.Add(24,-3,"SIO2");

	long pos = c.FindDMP("SIO2",3 ,fX,fY);

	if(pos == -1){
		cout<<"Test6 pass" << endl;
		return true;
	}else{
		cout<<"Test6 fail" << endl;
		return false;
	}
}

//Normal
bool FindDMPTest7(){
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
		cout<<"Test7 pass" << endl;
		return true;
	}else{
		cout<<"Test7 fail" << endl;
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
		cout<<"Test8 pass" << endl;
		return true;
	}else{
		cout<<"Test8 fail" << endl;
		return false;
	}
}


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
