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
	void Display();
	char* GetData(float x, float y);


//------------------------------------------------- Surcharge d'opérateurs

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
    int longueur;
    Mesure *tab ;
};

//--------------------------- Autres définitions dépendantes de <Cartography>

#endif // CARTOGRAPHY_H_
