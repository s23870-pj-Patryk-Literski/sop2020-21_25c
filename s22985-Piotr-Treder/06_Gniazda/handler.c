
#include <stdio.h>
#include <signal.h>
#include <unistd.h>


/* przykład programu który obsługuje sygnały */
void registerHandler();
void signalHandler(int);

int main() {
    int x = 1;
    registerHandler();  /* wywołujemy funkcję, która będzie wyłapywała akcję*/

    while (x != 0) {
        fflush(stdout);
        scanf("%d", &x);
    }

    return 0;

}

void signalHandler(int s){
    registerHandler();  /* w przypadku wyłapania np. Ctrl+C (wysłanie signalu do obecnie uruchomionego programu ) */
    printf("Handler triggered. s = %d\n", s);
}

void registerHandler() {
    sigset_t iset;          
    struct sigaction act; 
    /* w tej strukturze są dostępne zmienne 
         struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
 */


    sigemptyset(&iset); /* ustawienie wszystkich masek na 0 */

    act.sa_handler = &signalHandler;
    act.sa_mask = iset; 
    act.sa_flags = 0; 

    sigaction(SIGINT, &act, NULL); /* SIGINT - numer stałej w signal.h  <- 2, &act struktura sigaction opisująca jaką uruchomić funkcji, ustawienie maski ( to co powyżej 35-37 )  */
    /* sigaction jest używany do zmiany akcji wziętej z procesu  */
}