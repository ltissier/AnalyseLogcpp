#include "logreader.h"
#include <iostream>
#include <cstring>
#include <string>
#include "logMap.h"
int main(int argc, char const *argv[])
{


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
                cout << "nom de fichier : " << nomfichier << endl;
                continue;
              }else{
                cout << "erreur dans le format du fichier dot" << endl;
                continue;
              }
            }

          }

          // traitement de [-e]
          if(excl==0){
            if(strcmp(argv[i],"-e")==0){
                excl = 1;
                  cout << "vous avez choisi d'exclure les documents de type image, css ou javascript " << endl;
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
                int h = stoi(argv[i]);
                if(h>=0 && h<=23){
                    heure = h;
                    cout << "vous avez choisi de ne prendre en compte que les logs dans l'heure " << heure << endl;
                    continue;
                }else{
                  cout << "erreur dans le format d'heure de tri" << endl;
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
            cout << "fatal error dans le nom de fichier log"<< endl;
            return 0;
        }

        if((graph==1)&&(graphName==0||(triHeure==1&&heure==-1))){
            cout << "erreur critique dans le lancement du programme " << endl;
            cout << "veuillez relancer le programme en corrigeant les parametres" << endl;
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
            if ((graph==1)&& (graphName == 1))
            {
              selectedLogs.generateGraph(nomfichier);
            }
            selectedLogs.tenMostVisited();
          }
          else
          {
            //Méthode de chargement avec exclusion seule
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
