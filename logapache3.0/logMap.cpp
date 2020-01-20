

//---------- Réalisation de la classe <logMap> (fichier logMap.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel

#include <sstream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include "logMap.h"

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


logMap::logMap (string nomFichier, char subdelim) : crawler(nomFichier,subdelim)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <logMap>" << endl;
#endif


} //----- Fin de logMap

void logMap::insert(string cible, string referrer){
  cout << "test insert"<< endl;
  map<string,cibleViewers>::iterator it;
  it = maplogs.find(cible);
  if (it != maplogs.end()){
    cout << "cible trouvée" << endl;
    cout << "cible : " << it->first << endl;
    map<string,int>::iterator itpetitemap;
    itpetitemap = it->second.first.find(referrer);
    if (itpetitemap != it->second.first.end()){
      // le referrer est trouvé
      itpetitemap->second++;
      it->second.second++;

      cout << "referrer : " << itpetitemap->first << endl;
      cout << "nombre de vues pour ce couple ref/ cible : " << itpetitemap->second << endl;
    }else{
      // cible non trouvée
      cout << "referrer non trouvé " << endl;
      it->second.first.insert(pair<string,int>(referrer,1));
      it->second.second++;
    }
    cout << "nombre de vues totales pour cette cible : " << it->second.second << endl;
  }else{
    cout << "cible non trouvée" << endl;
    map<string,int> petiteMap;
    petiteMap.insert(pair<string,int>(referrer,1));
    maplogs.insert(pair<string,cibleViewers>(cible,pair<refererValue,int>(petiteMap,1)));

  }

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

void logMap:: generateGraph (string nom) // ligne à taper dans le terminal : dot -Tps testGraph.dot -o hw.ps
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
    ofstream fichier(nom,ios::out|ios::trunc);
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
