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
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <vector>

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

void logMap :: insertTest(string s, string s1, string s2, string s3, int n)
{
    map<string,int> petiteMap;
    petiteMap.insert(pair<string,int>(s1,12));
    petiteMap.insert(pair<string,int>(s2,1));
    petiteMap.insert(pair<string,int>(s3,2));
    map<string,cibleViewers>::iterator iterateur;
    iterateur = this->maplogs.end();
    this->maplogs.insert(pair<string,cibleViewers>(s,pair<refererValue,int>(petiteMap,n)));  
}

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
        cout << revIt->second << endl;

    }
}

void logMap:: generateGraph () // ligne à taper dans le terminal : dot -Tps testGraph.dot -o hw.ps
{
    #ifdef MAP
    cout << "Appel a la méthode <generateGraph> de <logMap>" << endl;
    #endif
    cout<<endl;
    int i=1;
    int j =1;
    vector<string> nodes;
    map<string,cibleViewers>::iterator iterateur1;
    map<string,int> :: iterator  iterateur2;
    ofstream fichier("testGraph.dot",ios::out|ios::trunc);
    string entete= {"node"};
    string lien ={" -> "};
    string label = " [label=\"";
    string fermeture = "\"];";
    string retourAlaligne = "\r\n";
    fichier << "digraph{";
    map<string,string> dejaCree;
    map<string,string>::iterator existe;
   

    for (iterateur1 = maplogs.begin(); iterateur1 != maplogs.end(); ++iterateur1, ++i)
    {
        string nb= to_string(i);
        string aStocker = {iterateur1->first};
        string numNoeud={entete+nb};
        existe = dejaCree.find(aStocker);
        if (existe == dejaCree.end())
        {
            string aEnvoyer = {numNoeud+label+aStocker+fermeture+retourAlaligne};
            fichier << aEnvoyer;
            dejaCree.insert(pair<string,string>(aStocker,numNoeud));
            existe = dejaCree.find(aStocker);
        }
        string numLien1 = {existe->second};
        for (j=1,iterateur2 = iterateur1->second.first.begin(); iterateur2 != iterateur1->second.first.end(); ++iterateur2, ++j)
        {
            string nb2= to_string(j);
            string nb21 = {nb+nb2};
            string numSousNoeud = {entete+nb21};
            string aStocker2 = {iterateur2->first};
            existe = dejaCree.find(aStocker2);
            if (existe == dejaCree.end())
            {
                string aEnvoyer2 = {numSousNoeud+label+aStocker2+fermeture+retourAlaligne};
                fichier << aEnvoyer2;
                dejaCree.insert(pair<string,string>(aStocker2,numSousNoeud));
                existe = dejaCree.find(aStocker2);
            }
            string ponderation = to_string(iterateur2->second);
            string numLien2 = {existe->second};
            string joindre = {numLien1+lien+numLien2+label+ponderation+fermeture};
            fichier << joindre;
            
            
        }
    }

    fichier << "}";
  fichier.close();
  system("dot -Tps testGraph.dot -o hw.ps");
  cout<< "Graph créé avec succès" << endl;
}


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

logMap::logMap ()
{
    map<string,cibleViewers> maplogs;

}
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

        cout << tokenizedLine.at(cible) << ' ';
        cout << tokenizedLine.at(referrer) << ' ';
        cout << endl;

}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

