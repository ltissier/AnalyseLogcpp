#include "logMap.h"
int main(int argc, char const *argv[])
{
        string nomfichier("anonyme.log");
        logMap map(nomfichier,' ');
        map.top10();
	return 0;
}
