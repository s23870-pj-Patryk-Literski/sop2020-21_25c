#include <stdio.h>
#include <stdlib.h>
int (*f[3])(int, int);
int maksimum(int a, int b)
{
        if(a>b)
        {
                return a;
        }
        return b;
}

int minimum(int p, int q)
{
        if(p>q)
        {
                return q;
        }
        return p;
}

int suma(int x, int y)
{
        return x + y;
}

int forAll(int* t,int w, int ktoraF)
{
        int i,wynik=*(t);
        for(i = 1; i < w; ++i)
        {
                wynik = (*f[ktoraF])(wynik,*(t + i));
        }
        printf("wynik to: %d \n",wynik);
        return wynik;
}
int main()
{
        int wielkosc,*table,i,funkcja;
        f[0] = maksimum;
        f[1] = minimum;
        f[2] = suma;

        printf("Podaj wielkosc tablicy: ");
        scanf ("%d",&wielkosc);

        table = (int*) malloc(wielkosc * sizeof(int));
        if(table == NULL)
        {
                printf("Nie mozna przypisac pamieci");
        }

        printf("Podaj elementy:\n");
        for(i = 0; i<wielkosc; ++i)
        {
                scanf("%d", table + i);
        }

        printf("Ktorej funkcji uzyc?\n");
        scanf("%d",&funkcja);

        forAll(table,wielkosc,funkcja);

        return 0;

}


