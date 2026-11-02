#include <stdio.h>
#include <unistd.h>

int main(void) {
    // Processo padre con le variabili
    int base = 5;
    printf("base: %d\n", base);
    int altezza = 10;
    printf("altezza: %d\n", altezza);
    int risultato = 0;
    printf("processo padre\n");

    // Creazione processo figlio
    int pid = fork();

    if (pid < 0) {
        printf("Errore creazione processo figlio\n");
        return 1;
    } 
    else if (pid == 0) {
        // Codice figlio
        risultato = 2 * (base + altezza);
        printf("[FIGLIO] ID: %d (padre ID: %d)\n", getpid(), getppid());
        printf("[FIGLIO] calcolo perimetro %d\n\n", risultato);
    } 
    else {
        // Codice padre
        risultato = base * altezza;
        printf("[PADRE] ID: %d\n", getpid());
        printf("[PADRE] Calcolo area: %d\n\n", risultato);
    }

    return 0;
}
