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
#include "logreader.h"
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


logreader::logreader (string nomFichier, char subdelim) : fichier(nomFichier.c_str())
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <logreader>" << endl;
#endif
    nomfichier = nomFichier;

    delim = subdelim;

} //----- Fin de logMap


logreader::~logreader ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <logreader>" << endl;
#endif
} //----- Fin de ~logMap


  vector<string> logreader::next(){
    //cout << "parsing line " << endl;
    vector<string> result;
          string line;
          getline(fichier,line);
      //    cout << line << endl;

          stringstream ges(line);

          string subtoken;
          while (getline(ges, subtoken, delim)) {
              result.push_back(subtoken);
          }

      //    cout << result.size() << endl;
          return result;



}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
