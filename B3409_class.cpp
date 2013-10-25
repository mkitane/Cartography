/*************************************************************************
                           Cartography  -  description
                             -------------------
    debut                : 11 oct. 2013
    copyright            : (C) 2013 par kbenhmida
*************************************************************************/

//---------- Realisation de la classe <Cartography> (fichier Cartography.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
#include <iostream>
//------------------------------------------------------ Include personnel
#include "B3409_class.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Methodes publiques
bool Cartography::Add(float fX, float fY, char* pszDMP)
// Algorithme :
// Debut Methode
//
// Si longueur du tableau > longueur MAX tableau
//		retourner faux
// Fin Si
//
// Pour i allant de 0 ˆ longueur du tableau
//		Si coordonne x de tableau[i] == fX et coordonnee y de tableau[i] == fY
//			retourner faux
//		Fin Si
// Fin Pour
//
// Remplir tableau[longueur] avec la mesure passee en parametre
// incrementer la longueur du tableau
//
// Fin methode
{
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
	longueur ++;

	return true;
}//----- Fin de Methode


long Cartography::FindDMP(char* pszDMP, long lFirstPos, float& fX, float& fY)
// Algorithme :
// Debut Methode
// Pour i allant de lFirstPos a longueur du tableau
//		Si pszDMP est egale a description de tab[i]
//			fX = coordonnee x de tab[i]
//			fY = coordonnee y de tab[i]
//			retourner i (position de la mesure dans le tableau)
//		Fin Si
// Fin Pour
//
// Retourner -1
//
//Fin Methode
{
	for(int i = lFirstPos; i<longueur ; i++ ){
		if(compareStrings(pszDMP, tab[i].description)){
			fX = tab[i].x;
			fY = tab[i].y;
			return i;
		}
	}
	return -1;
}//----- Fin de Methode

long Cartography::Count()
// Algorithme :
// Debut Methode
// 	Retourner longueur tableau
// Fin Methode
{
	return longueur;
}//----- Fin de Methode


long Cartography::Count(char* pszDMP)
// Algorithme :
// Debut Methode
// size = 0
// Pour i allant de 0 a longueur du tableau
//		Si pszDMP == description de tab[i]
//			incrementer size
//		Fin Si
// Fin Pour
// retourner size
// Fin Methode
{
	int size = 0 ;

	for(int i = 0 ; i < longueur ; i++){
		if(compareStrings(pszDMP,tab[i].description)){
			size++;
		}
	}

	return size;
}//----- Fin de Methode

void Cartography::Display()
//void Cartography::Display();
// Algorithme :
// Debut Methode
// Pour i allant de 0 a longueur du tableau
//		afficher sur la sortie ecran description de la matiere et ses coordonnes
// Fin Pour
// Fin Methode
{
	for(int i=0; i<longueur ;i++){
		cout<< "Matiere " << tab[i].description << " en : (" << tab[i].x << "," << tab[i].y << ")" << endl;
	}
}//----- Fin de Methode


char* Cartography::GetData(float x, float y)
// Algorithme :
// Debut Methode
// Pour i allant de 0 a longueur du tableau
//		Si coordonne x de tab[i] == x et coordonnee y de tab[i] == y
//			retourner description de tab[i]
//		Fin Si
// Fin Pour
//
// Retourner null sinon
// Fin Methode
{
	for(int i = 0; i<longueur ; i++ ){
			if(tab[i].x == x && tab[i].y == y)
				return tab[i].description;
	}

	return NULL;
}//----- Fin de Methode

//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
Cartography::Cartography ( ) : longueur(0), tab(new Mesure[MAX])
// Algorithme :
//	Definir la valeur de la variable longueur a 0
//	Affecter au pointeur de tableau un tableau de taille MAX et de type Mesure
{
	//tab = new Mesure [MAX] ;
#ifdef MAP
    cout << "Appel au constructeur de <Cartography>" << endl;
#endif
} //----- Fin de Cartography


Cartography::~Cartography ( )
// Algorithme :
//	Supprimer le tableau cree par un new
{
	delete [] tab;

#ifdef MAP
    cout << "Appel au destructeur de <Cartography>" << endl;
#endif
} //----- Fin de ~Cartography


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Methodes protegees
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

	for(int i=0;firstString[i];i++){
		if(firstString[i] != secondString[i])
			return false;
	}

	return true;
}


