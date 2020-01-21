#include "logMap.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
   	logMap map;
    map.insertTest("noeud1","noeud11","noeud12","noeud13",10);
    map.insertTest("noeud2","noeud21","noeud22","noeud23",9);
    map.insertTest("noeud3","noeud31","noeud32","noeud33",8);
    map.insertTest("noeud4","noeud41","noeud42","noeud43",7);
    map.insertTest("noeud5","noeud51","noeud52","noeud53",6);
    map.insertTest("noeud6","noeud61","noeud62","noeud63",5);
    map.insertTest("noeud7","noeud71","noeud72","noeud73",4);
    map.insertTest("noeud8","noeud81","noeud82","noeud83",3);
    map.insertTest("noeud9","noeud91","noeud92","noeud93",2);
    map.insertTest("noeud10","noeud101","noeud102","noeud103",1);
    map.insertTest("noeud11","noeud111","noeud112","noeud113",0);
    map.insertTest("noeud12","noeud121","noeud122","noeud123",0);
    map.generateGraph();
    cout<< "On est là" <<endl;
    map.tenMostVisited();
	return 0;
}
