/*************************************************************************
                           logMap  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <logMap> (fichier logMap.h) ----------------
#if ! defined ( LOGREADER_H )
#define LOGREADER_H
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

class logreader
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    logreader(string nomFichier , char subdelim = ' ');
    // Mode d'emploi :
    //
    // Contrat :
    //

    int next(vector<string>* result);


    virtual ~logreader ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    enum Indice { IP = 0, dateheure = 1 , fuseauhoraire = 2, typederequete = 3, cible = 6, protocole = 7, referrer = 10, agent = 11};


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés


ifstream fichier;

string nomfichier;
char delim;



};

//-------------------------------- Autres définitions dépendantes de <logMap>

#endif // LOGMAP_H
