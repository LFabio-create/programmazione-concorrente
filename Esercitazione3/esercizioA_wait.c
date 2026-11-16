#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if (pid == 0) {
        printf("Sono il figlio\n");
        exit(0);
    }
    else if (pid > 0) {
        wait(NULL);
        printf("Il figlio ha terminato\n");
    }
    else {
        printf("Errore nella creazione del figlio\n");
    }

    return 0;
}
