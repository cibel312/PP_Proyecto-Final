/* 
   Compilar: gcc -fopenmp atomic.c -o prueba02
   Ejecutar: ./prueba02
*/

#include <stdio.h>
#include <omp.h>

int main() {
    int A[] = {8, 5, 4, 11, 2, 6, 3, 10, 9};  // Corregido el nombre del array y la sintaxis
    int N = sizeof(A)/sizeof(A[0]);
    int conteo = 0;
    
    #pragma omp parallel for num_threads(3)
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
            #pragma omp atomic
            conteo++;  // Corregido el nombre de la variable (contest -> conteo)
        }
    }

    printf("Cantidad de elementos pares: %d\n", conteo);
    return 0;
}