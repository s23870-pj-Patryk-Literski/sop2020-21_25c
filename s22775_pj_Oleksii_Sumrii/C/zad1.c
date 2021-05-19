#define _CRT_SECURE_NOWARNINGS 
#include <stdio.h>

int main() {
	int licz = 0;
	int suma = 0;
	int n = 0;
	int i = 0;
	printf("Ilosc wprowadzonych liczb: ");
	scanf("%d\n", &n); 
		while(i < n)
		{
			scanf("%d\n", &licz);
			suma+=licz;
			i++;
		}
	printf("Suma = %d\n", suma);
	return 0;
}

