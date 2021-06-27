#include<stdio.h>

int main(int argc, char **argv){

	FILE *plik1;
	FILE *plik2;
	if(argc == 1){
		plik1 = fopen("liczby","r");
		plik2 = fopen("liczby","r");
	}
	if(argc == 2){
		plik1 = fopen(argv[1],"r");
		plik2 = fopen(argv[1], "r");
	}
	if(plik1 == NULL || plik2 == NULL){
		printf("blad argumentu\n");
		return 1;
	}
	
	
	int liczba; /*wszystkich linii */
	fscanf(plik1,"%d",&liczba);
	printf("ilosc elementow do wypisania wynosi %d\n",liczba-1);
	
	int k=0;
	char lines[100]; /* dozwolona wielkosc linii */
	int tablo[liczba];

	while ((fscanf(plik2,"%[^\n]\n", lines))!= EOF)
	{
		tablo[k]=atoi(lines);
		k++;
	}	

	printf("\nliczby wypisane od tylu\n");
	for(k = liczba; k > 0; k--){
		printf("< %d\n",tablo[k]);
	}

	fclose(plik1);
	fclose(plik2);
	return 0;	
}
