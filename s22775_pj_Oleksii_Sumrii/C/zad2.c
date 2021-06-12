#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int wie = 0;
	int a = 0;
	int b = 0;
	char* sym = "*";
	if (argc != 2)
	{
		return 1;
	}
	
	wie = atoi(argv[1]);
	printf("W ile wierszow chcesz choinke? %d %s\n ", wie, sym);
	
	for(;a < wie; a++)
	{
		for(b = wie - a; b > 0; b--)
		{
			printf(" ");
		}
		for(b = 0; b < (a * 2) - 1; b++)
		{
		printf("%s", sym);
		}
		printf("\n");
	}
	return 0;
}

