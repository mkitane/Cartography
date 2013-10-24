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
// Role de la classe <Cartography>
// Cette classe permet de manipuler, c'est � dire chercher, ajouter, gerer
// des mesures de type DMP.
//------------------------------------------------------------------------ 

class Cartography
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques
    // bool Add (float fX, float fY, char* pszDMP);
    // Mode d'emploi :
    //	Methode qui permet de rajouter une mesure DMP a la classe.
    // Contrat :
    //  -Ne pas ajouter un point dont les coordonnees fX et fY ont deja
	// ete rajoutee a la classe.
	//	-Ne pas ajouter plus d'un million d'elements.
	bool Add(float fX, float fY, char* pszDMP);



	//long Count();
	// Mode d'emploi :
	//	Compte et renvoie le nombre de mesures stockees au sein de la classe.
	// Contrat :
	//
	long Count();



	//long Count(char* pszDMP);
	// Mode d'emploi :
	//	Compte et renvoie le nombre de mesures ayant pour description le
	// char* passe en parametre.
	// Contrat :
	//
	long Count(char* pszDMP);

	//long FindDMP(char* pszDMP, long lFirstPos, float& fX, float& fY);
	// Mode d'emploi :
	//	Renvoie la position dans notre tableau du premier element ayant pour
	//  description la chaine de caracteres pszDMP.
	//  Elle remplit aussi les deux float fX et fY passes en parametres par
	//  la position du premier element ayant pour descrption la chaine de caracteres
	//  pszDMP.
	// Contrat :
	//
	long FindDMP(char* pszDMP, long lFirstPos, float& fX, float& fY);


	//void Display();
	// Mode d'emploi :
	//	Affiche tous les elements DMP stockes dans le tableau de la classe.
	// Contrat :
	//
	void Display();


	//char* GetData(float x, float y);
	// Mode d'emploi :
	//	Recupere la description de lelement ayant pour coordonnees, les coordonnees
	//  passes en parametre.
	// Contrat :
	//
	char* GetData(float x, float y);


//------------------------------------------------- Surcharge d'operateurs

//-------------------------------------------- Constructeurs - destructeur
    Cartography ( );
    // Mode d'emploi :
    //	Constructeur de la classe.
    // Contrat :
    //

    virtual ~Cartography ( );
    // Mode d'emploi :
    //	Destructeur de la classe.
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Methodes protegees
    bool compareStrings(char* firstString, char* secondString);
    int sizeOfString(char* string);
//----------------------------------------------------- Attributs proteges
    int longueur;
    Mesure *tab ;
};

//--------------------------- Autres definitions dependantes de <Cartography>

#endif // CARTOGRAPHY_H_
