#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void signalHandler(int s){
    printf("Zły klawisz, zostaniesz ze mna na dobre %d\n",s);
}

int main(){
    int input=1;

    while(input!=0){
        signal(SIGINT,&signalHandler);
        printf("Naciśnij klawisz 0 aby zakończyć program \n");
        scanf("%d",&input);
    }
    return 0;
}