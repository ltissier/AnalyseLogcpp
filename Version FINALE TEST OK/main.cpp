#include "logreader.h"
#include <iostream>
#include <cstring>
#include <string>
#include "logMap.h"
#include <ctype.h>
int main(int argc, char const *argv[])
{
        //
        string nomfichier;
        int graph = 0;
        int graphName = 0;
        int excl = 0;
        int triHeure=0;
        int heure=-1;
        for(int i=0; i<argc; i++){

          // traitement de [-g nomfichier.dot]
          if(graph==0){
            if(strcmp(argv[i],"-g")==0){
                graph = 1;
                continue;
            }
          }else{
            if(graphName == 0 ){

              string str(argv[i]);
              string delim(".");
              std::size_t current, previous = 0;
              current = str.find(delim);
              previous = current + 1;
              current = str.find(delim, previous);
              if(strcmp(str.substr(previous, current - previous).c_str(),"dot")==0){
                graphName = 1;
                nomfichier = str;
                //cout << "Nom de fichier : " << nomfichier << endl;
                continue;
              }else{
                cerr << "Erreur dans le format du fichier dot" << endl;
                continue;
              }
            }

          }

          // traitement de [-e]
          if(excl==0){
            if(strcmp(argv[i],"-e")==0){
                excl = 1;
                  cout << "Vous avez choisi d'exclure les documents de type image, css ou javascript " << endl;
                continue;
            }
          }

          //traitement de -t heure
          if(triHeure==0){
            if(strcmp(argv[i],"-t")==0){
                triHeure = 1;
                continue;
            }
          }else{
 		
            if(heure == -1){
		if ((isdigit(argv[i][0])==0)||(isdigit(argv[i][1])==0))
                {
		  cerr << "Erreur dans le format d'heure de tri" << endl;
                  cerr<< "Veuillez rentrer une heure" << endl;
                  return 0;
                }
                int h = stoi(argv[i]);
                if(h>=0 && h<=23){
                    heure = h;
                    cout << "Vous avez choisi de ne prendre en compte que les logs dans l'heure " << heure << endl;
                    continue;
                }
		else{
                  cerr << "Erreur dans le format d'heure de tri" << endl;
		  cerr<< "Veuillez rentrer une heure" << endl;
		  return 0;
                }
            }
          }
        }

          string nomfichierlog(argv[argc-1]);
        string delim(".");
        std::size_t current, previous = 0;
        current = nomfichierlog.find(delim);
        previous = current + 1;
        current = nomfichierlog.find(delim, previous);
        if(strcmp(nomfichierlog.substr(previous, current - previous).c_str(),"log")!=0){
            cerr << "Fatal error dans le nom de fichier log"<< endl;
            return 0;
        }

        if((graph==1)&&(graphName==0||(triHeure==1&&heure==-1))){
            cerr << "Erreur critique dans le lancement du programme " << endl;
            cerr << "Veuillez relancer le programme en corrigeant les parametres" << endl;
            return 0;
        }
        cout << argv[argc-1] << endl;
        char subdelim(' ');
        logMap selectedLogs(nomfichierlog,subdelim);

        if ( excl == 1)
        {
          if ((triHeure == 1) && (heure != -1))
          {
            //Méthode de chargement avec exclusion et tri de l'heure
            selectedLogs.loadlogs_timeexclusion(heure);
            if ((graph==1)&& (graphName == 1))
            {
              selectedLogs.generateGraph(nomfichier);
            }
            selectedLogs.tenMostVisited();
          }
          else
          {
            //Méthode de chargement avec exclusion seule
            selectedLogs.loadlogs_exclusion();
            if ((graph==1)&& (graphName == 1))
            {
              selectedLogs.generateGraph(nomfichier);
            }
            selectedLogs.tenMostVisited();
          }
        }
        else {
          if ((triHeure == 1) && (heure != -1))
          {
            //Méthode de chargement avec exclusion de l'heure uniquement
            selectedLogs.loadlogs_time(heure);
            if ((graph==1)&& (graphName == 1))
            {
              selectedLogs.generateGraph(nomfichier);
            }
            selectedLogs.tenMostVisited();
          }
        }
        if ((excl != 1)&& (triHeure != 1))
        {
          selectedLogs.loadlogs();
          if ((graph==1)&& (graphName == 1))
          {
            selectedLogs.generateGraph(nomfichier);
          }
          selectedLogs.tenMostVisited();
        }



	return 0;
}
