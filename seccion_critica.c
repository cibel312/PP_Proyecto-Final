/*Compilarlo con un compilador que soporte OpenMP, como gcc:
gcc -fopenmp seccion_critica.c -o prueba01
Ejecutarlo:
./prueba01
*/

#include <stdio.h>
#include <omp.h>

int main() {
    int total = 0;
    int datos[] = {5, 3, 7, 2, 9, 4, 6, 1};
    int N = sizeof(datos)/sizeof(datos[0]);
    
    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < N; i++) {
        int parcial = datos[i] * 2; // trabajo por hilo
        
        #pragma omp critical
        {
            total += parcial; // solo un hilo puede entrar aquí a la vez
            printf("Hilo %d sumó %d -> total parcial = %d\n", omp_get_thread_num(), parcial, total);
        }
    }

    printf("Suma final: %d\n", total);
    return 0;
}