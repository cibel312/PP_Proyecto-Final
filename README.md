ESTUDIANTES:
Alvaro Rimbaud Poma Alegre
Cristian Rodriguez Huaraz
# Programa Paralelo con OpenMP

Este repositorio contiene un programa en C que demuestra el uso de OpenMP para paralelización, específicamente utilizando:
- Regiones paralelas
- Barreras de sincronización
- Asignación de trabajo a hilos

## Descripción del Código

El programa realiza las siguientes operaciones:
1. Crea 4 hilos paralelos usando `#pragma omp parallel`
2. Cada hilo:
   - Obtiene su ID con `omp_get_thread_num()`
   - Calcula el cuadrado de su ID y lo almacena en un arreglo compartido (`resultado[id] = id * id`)
   - Imprime su cálculo individual
3. Sincroniza todos los hilos con `#pragma omp barrier`
4. El hilo maestro (id=0) suma todos los resultados y muestra el total

## Compilación y Ejecución

Para compilar el programa:
```bash
gcc -fopenmp programa.c -o programa
