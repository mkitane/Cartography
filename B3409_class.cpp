/*************************************************************************
                           Cartography  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par kbenhmida
*************************************************************************/

//---------- Réalisation de la classe <Cartography> (fichier Cartography.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
//------------------------------------------------------ Include personnel
#include "B3409_class.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cartography::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Cartography::Add(float fX, float fY, char* pszDMP){


	if(longueur>=MAX){
		cout<< "Taille Maxi depassee" << endl;
		return false;
	}

	for(int i = 0; i<longueur ; i++ ){
		if(tab[i].x == fX && tab[i].y == fY)
			return false;
	}

	Mesure m = {fX,fY,pszDMP};
	tab[longueur] = m;
	longueur ++ ;

	return true;
}


// type Cartography::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
long Cartography::FindDMP(char* pszDMP, long lFirstPos, float& fX, float& fY){
	for(int i = lFirstPos; i<longueur ; i++ ){
		if(compareStrings(pszDMP, tab[i].description)){
			fX = tab[i].x;
			fY = tab[i].y;
			return i;
		}
	}
	return -1;
}

// type Cartography::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
long Cartography::Count(){
	return longueur;
}

long Cartography::Count(char* pszDMP){
	int size = 0 ;

	for(int i = 0 ; i < longueur ; i++){
		if(compareStrings(pszDMP,tab[i].description)){
			size++;
		}
	}

	return size;
}


void Cartography::Display(){
	for(int i=0; i<longueur ;i++){
		cout<< "Matiere " << tab[i].description << " trouvee a la position : (" << tab[i].x << "," << tab[i].y << ")" << endl;
	}
}
char* Cartography::GetData(float x, float y){

	for(int i = 0; i<longueur ; i++ ){
			if(tab[i].x == x && tab[i].y == y)
				return tab[i].description;
	}

	return NULL;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Cartography::Cartography ( ) : longueur(0), tab(new Mesure[MAX])
// Algorithme :
//
{
	//tab = new Mesure [MAX] ;

#ifdef MAP
    cout << "Appel au constructeur de <Cartography>" << endl;
#endif
} //----- Fin de Cartography


Cartography::~Cartography ( )
// Algorithme :
//
{
	delete [] tab;


#ifdef MAP
    cout << "Appel au destructeur de <Cartography>" << endl;
#endif


} //----- Fin de ~Cartography


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int Cartography::sizeOfString(char* string){
	int size = 0 ;
	for(int i=0; string[i];i++){
		size++;
	}
	return size;
}



bool Cartography::compareStrings(char* firstString, char* secondString){

	if(sizeOfString(firstString) != sizeOfString(secondString)){
		return false;
	}

	for(int i=0; firstString[i];i++){
		if(firstString[i] != secondString[i])
			return false;
	}

	return true;
}


