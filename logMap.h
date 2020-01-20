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
#include "logreader.h"

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
    string filterrequest(string adress);
    string normalizeRef(string ref);
    string normalizeCible(string cible);
    void insert(string referrer, string cible);
    bool compare(const pair<int, int>&a, const pair<int, int>&b);

    logMap (string nomFichier , char subdelim = ' ');
    // Mode d'emploi :
    //
    // Contrat :
    //
    void tenMostVisited ();

    void generateGraph(string nom);

    void loadlogs();
    void loadlogs_time(int time);
    void loadlogs_exclusion();
    void loadlogs_timeexclusion(int time);

    logMap();


    virtual ~logMap ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
typedef map<string,int> refererValue;
typedef pair<refererValue,int> cibleViewers;
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

//typedef pair<string,cibleViewers> cmap;

map<string,cibleViewers> maplogs;
ifstream fichier;
logreader crawler;
string nomfichier;
char delim;



};

//-------------------------------- Autres définitions dépendantes de <logMap>

#endif // LOGMAP_H
