/*************************************************************************
                           logMap  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <logMap> (fichier logMap.h) ----------------
#if ! defined ( LOGMAP_H )
#define LOGMAP_H
using namespace std;
#include <map>
#include <string>
#include <vector>

#include <fstream>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <logMap>
//
//
//------------------------------------------------------------------------

class logMap
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :input
    //


//----------------------------------------s

//-------------------------------------------- Constructeurs - destructeur
    logMap ( const logMap & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    logMap (string nomFichier , char subdelim = ' ');
    // Mode d'emploi :
    //
    // Contrat :
    //
	vector<string> tokenizeLine(string line);
	
	void top10();
	

    virtual ~logMap ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
typedef map<string,int> refererValue;
typedef pair<refererValue,int> cibleViewers;
//typedef pair<string,cibleViewers> cmap;

map<string,cibleViewers> maplogs;
ifstream fichier;

string nomfichier;
char delim;



};

//-------------------------------- Autres définitions dépendantes de <logMap>

#endif // LOGMAP_H

