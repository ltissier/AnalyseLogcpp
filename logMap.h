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

#include <map>
#include <string>

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
    // Contrat :
    //


//----------------------------------------s

//-------------------------------------------- Constructeurs - destructeur
    logMap ( const logMap & unEnsemble );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    logMap ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

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

};

//-------------------------------- Autres définitions dépendantes de <logMap>

#endif // LOGMAP_H

