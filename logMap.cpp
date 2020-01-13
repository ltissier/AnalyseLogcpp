/*************************************************************************
                           logMap  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <logMap> (fichier logMap.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "logMap.h"
#include <sstream>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type logMap::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
logMap::logMap ( const logMap & unEnsemble )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <logMap>" << endl;
#endif
} //----- Fin de logMap (constructeur de copie)


logMap::logMap (string nomFichier, char subdelim) : fichier(nomFichier.c_str())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <logMap>" << endl;
#endif
    nomfichier = nomFichier;

    delim = subdelim;

} //----- Fin de logMap


logMap::~logMap ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <logMap>" << endl;
#endif
} //----- Fin de ~logMap

vector<string> logMap::tokenizeLine(string line)
{
#ifdef MAP
    cout << "Appel à <TokenizeLine> de <logMap>" << endl;
#endif

        vector<string> result;
        stringstream ges(line);

        string subtoken;
        while (getline(ges, subtoken, delim)) {
            result.push_back(subtoken);
        }
        return result;
}
void logMap::top10(){
    cout << "test " << endl;
    string line;

    getline(fichier,line);

        vector<string> tokenizedLine = tokenizeLine(line);
        cout << tokenizedLine.at(6) << ' ';
        cout << tokenizedLine.at(10) << ' ';
        cout << endl;




}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

