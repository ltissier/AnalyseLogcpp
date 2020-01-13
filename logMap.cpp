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
#include <iterator>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type logMap::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

bool logMap :: compare(const pair<int, int>&a, const pair<int, int>&b)
{
	return a.second<b.second;
}

void logMap :: tenMostVisited ()
{
	map<string,cibleViewers>::iterator iterateur;
	multimap<int,string> top;
	for (iterateur = maplogs.begin(); iterateur != maplogs.end(); ++iterateur)
	{
		top.insert(pair<int,string>(iterateur->second.second,iterateur->first));
	}
	multimap<int,string>::reverse_iterator revIt;
	int cnt =0;
	for(revIt = top.rbegin(); (cnt<10)&&(revIt!=top.rend()) ;++revIt,++cnt)
	{
		cout << revIt->second;

	}

}
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


logMap::logMap ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <logMap>" << endl;
#endif
} //----- Fin de logMap



logMap::~logMap ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <logMap>" << endl;
#endif
} //----- Fin de ~logMap


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

