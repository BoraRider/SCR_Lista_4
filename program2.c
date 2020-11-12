#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//===================================
void funkcja(){

    printf("PID: %d\n", getpid());
    sleep(1);

}
//===================================
void sygnal1(int signum) {

    printf("Sygnal o numerze: %d\n", signum);
    exit(0);
}

void sygnal2(int signum) {

    printf("Sygnal o numerze: %d\n", signum);
}
void sygnal4(int signum) {

    ;
}
void sygnal3(int signum) {

    printf("Sygnal 10 \n");
    int licznik=0;
    for(licznik; licznik<=1000; licznik++){

        for(int sygnaly=0; sygnaly<=15; sygnaly++){
            signal(sygnaly, SIG_IGN);         
        }
        funkcja();

    }
    printf("Koniec petli\n");

        for(int sygnaly=0; sygnaly<=15; sygnaly++){
            signal(sygnaly, SIG_DFL);
        }        

}


int main() {

    signal(SIGUSR1, sygnal3); //sygnal 10
    signal(SIGUSR2, sygnal1); //sygnal 12
    signal(SIGTERM, sygnal2); //sygnal 15
    signal(SIGALRM, sygnal4); //sygnal 14

    while (1) {       
        funkcja();
    } 
}