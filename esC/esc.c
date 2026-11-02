#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    char comando;
    int led = 0;
    pid_t pid;

    while (1) {
        printf("\nInserisci comando (v = verde, r = rosso, g = giallo, q = esci): ");
        scanf(" %c", &comando);

        if (comando == 'q') {
            printf("Chiusura del programma.\n");
            break;
        }

        if (comando == 'v') {
            led = 1;
        } else if (comando == 'r') {
            led = 2;
        } else if (comando == 'g') {
            led = 3;
        } else {
            printf("Comando non valido. Riprova.\n");
            continue;
        }

        pid = fork();

        if (pid < 0) {
            perror("Errore nella creazione del processo figlio");
            exit(1);
        }

        if (pid == 0) {
            int intervallo_us = 0;
            char nome_led[10];

            if (led == 1) {
                snprintf(nome_led, sizeof(nome_led), "VERDE");
                intervallo_us = 300000;
            } else if (led == 2) {
                snprintf(nome_led, sizeof(nome_led), "ROSSO");
                intervallo_us = 700000;
            } else if (led == 3) {
                snprintf(nome_led, sizeof(nome_led), "GIALLO");
                intervallo_us = 1200000;
            }

            for (int i = 1; i <= 10; i++) {
                printf("LED %s ACCESO  (Lampeggio %d/10)\n", nome_led, i);
                usleep(intervallo_us);

                printf("LED %s SPENTO  (Lampeggio %d/10)\n", nome_led, i);
                usleep(intervallo_us);
            }

            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}
