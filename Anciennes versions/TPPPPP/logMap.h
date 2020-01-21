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

    void insertTest(string s, string s1, string s2, string s3, int n);

    bool compare(const pair<int, int>&a, const pair<int, int>&b);
	
	void top10();

    void tenMostVisited ();

    void generateGraph();
	
    logMap();

    virtual ~logMap ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

   
//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

//typedef pair<string,cibleViewers> cmap;
typedef map<string,int> refererValue;
typedef pair<refererValue,int> cibleViewers;
map<string,cibleViewers> maplogs;

ifstream fichier;

string nomfichier;
char delim;
enum Indice { IP = 0, dateheure = 1 , fuseauhoraire = 2, typederequete = 3, cible = 6, protocole = 7, referrer = 10, agent = 11};


};

//-------------------------------- Autres définitions dépendantes de <logMap>

#endif // LOGMAP_H

