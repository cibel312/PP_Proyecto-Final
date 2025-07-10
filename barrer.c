/*
    Compilar: gcc -fopenmp programa.c -o programa
    Ejecutar: ./programa
*/

#include <stdio.h>
#include <omp.h>

int main() {
    int resultado[4];
    
    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();
        resultado[id] = id * id; // etapa 1: cálculo

        printf("Hilo %d calculó %d\n", id, resultado[id]);

        #pragma omp barrier // todos esperan aquí

        // etapa 2: verificación sincronizada
        if (id == 0) {
            int suma = 0;
            for (int i = 0; i < 4; i++) suma += resultado[i];
            printf("Hilo 0 verifica suma total: %d\n", suma);
        }
    }

    return 0;
}