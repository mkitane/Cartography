/*************************************************************************
                           Cartography  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par kbenhmida
*************************************************************************/

//---------- Interface de la classe <Cartography> (fichier Cartography.h) ------
#if ! defined ( CARTOGRAPHY_H_ )
#define CARTOGRAPHY_H_

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 
const int MAX = 1000000;

//------------------------------------------------------------------ Types 
struct Mesure
{
	float x;
	float y;
	char* description;
};
//------------------------------------------------------------------------ 
// Rôle de la classe <Cartography>
//
//
//------------------------------------------------------------------------ 

class Cartography
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	bool Add(float fX, float fY, char* pszDMP);
	long Count();
	long Count(char* pszDMP);
	long FindDMP(char* pszDMP, long lFirstPos, float& fX, float& fY);
	void Display(Mesure m);  //pas sur du parametre
	char* GetData(float x, float y); // pas sur plutot :
	//int GetData(float x, float y);


//------------------------------------------------- Surcharge d'opérateurs
    Cartography & operator = ( const Cartography & unCartography );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cartography ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cartography ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées
    bool compareStrings(char* firstString, char* secondString);
    int sizeOfString(char* string);
//----------------------------------------------------- Attributs protégés
    Mesure *tab ;
    int longueur;
};

//--------------------------- Autres définitions dépendantes de <Cartography>

#endif // CARTOGRAPHY_H_
