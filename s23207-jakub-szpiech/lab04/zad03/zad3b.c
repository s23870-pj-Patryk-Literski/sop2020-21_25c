#include <stdio.h>
#include <stdlib.h>
int main (int argc, char** argv){
	int wiersze = 0;
	int aktualnyWiersz = 0;
	int aktualnyElement = 0;
	if (argc != 2) { /* zerowym elementem jest nazwa programu, a pierwszym jest pierwszy argument przekazany */
		return 1;
	}
	wiersze = atoi(argv[1]);
	/*scanf("%d\n", &wiersze); & dlatego, ze ta funkcja potrzebuje adres komorki pamieci do ktorej ma wpisac wartosc*/
	printf("Wypluwam choinke z wierszy: %d\n", wiersze);

	for(; aktualnyWiersz < wiersze; aktualnyWiersz++) {
		for(aktualnyElement = wiersze-aktualnyWiersz; aktualnyElement > 0; aktualnyElement--){
			printf(" ");
		}
		for(aktualnyElement = 0; aktualnyElement < (aktualnyWiersz*2)-1; aktualnyElement++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;

}

