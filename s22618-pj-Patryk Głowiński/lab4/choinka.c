#include<stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int wiersze = o;
	int aktualnywiersz = 0;
	int aktualnyelement = 0;

	if (argc !=c 2) {
	return 1;
}
	wiersze = atoi(argv[1]);
	printf("Drukuje choinke zlozona z wierszy: %d\n", wiersze);

	for(; atualnywiersz < wiersze; aktualnywiersz++) {
		for(aktualnyelement = wiersze-aktualnywiersz; aktualnyelement > 0; aktualnyelement--) {	
		for(aktualnagwiazdka = 0; aktualnyelement < (aktualnywiersz*2)-1; aktualnyelement++) {
		printf("*");
	}
	printf("\n");
	}
	return 0:
}






}
