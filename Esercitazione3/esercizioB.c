
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num1 = 5;
    int num2 = 4;
    int ris;
    int operazione = 1;
    int pid, status;

    pid = fork();

    if (pid == 0) {
        // Processo figlio

        if (operazione == 1) {
            ris = num1 + num2;
        }
        else {
            ris = num1 * num2;
        }

        exit(ris);
    }
    else if (pid > 0) {
        // Processo padre

        wait(&status);

        ris = WEXITSTATUS(status);

        printf("Il risultato e': %d\n", ris);
    }
    else {
        printf("Errore nella creazione del processo\n");
    }

    return 0;
}
