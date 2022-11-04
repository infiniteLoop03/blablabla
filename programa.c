#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double algoritmoBurbuja() {
    // Se lee el archivo
    int numeros[2000]; // Se crea el arreglo con el numero total de numeros
    int i = 0, j = 0, swap;
    FILE* archivo; // Se crea la variable puntero de tipo FILE

    if (archivo = fopen("setdatosedades.txt", "r")){ // Abriendo el archivo en modo lectura, si es True procede
    
        while (fscanf(archivo, "%d", &numeros[i]) != EOF){ // Mientras lea el archivo y guarde la posicion de numeros en i y sea diferente del End Of File sigue
            i++;
        }
        fclose(archivo); // Se cierra el archivo 
    }

    // Despues de leer el archivo de procede a implementar el algoritmo y a calcular su tiempo de ejecucion
    double tiempo = 0.0; // Variable para obtener el tiempo 
    clock_t begin = clock(); // Se inicializa el reloj

    // Algoritmo
    for(i = 0; i < 2000 - 1; i++){ // Foor loop que recorre todo el arreglo menos 1
        for(j = 0; j < 2000 - i - 1; j++) { // Foor loop anidado que recorre todo el arreglo menos el iterador del for externo menos 1
            if(numeros[j] > numeros[j + 1]){ // Si numeros en j es mayor a numeros en j + 1. Se guardan en swap el numero que esté en la posicion actual despues en la posicion actual se guarda el numero que esté adelante (j+1) y a numeros en j + 1 le asignmamos el numero dentro de la variable swap  
                swap = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = swap;
            }
        }
    }
    clock_t end = clock(); // Termina el proceso de reloj
    tiempo += (double)(end - begin) / CLOCKS_PER_SEC; // Se calcula el tiempo final 

    // Se procede a imprimir el arreglo ordenado
    printf("Se procede a imprimir el arreglo ordenado: \n");
    for (i = 0; i < 2000; i++) {
        printf("%d\n", numeros[i]);
    }

    // Se procede a retornar el tiempo de ejecucion del algoritmo en especifico
    return tiempo;
}

double algoritmoInsercion() {
    // Se lee el archivo
    int numeros[2000]; // Se crea el arreglo con el numero total de numeros
    int i = 0, j = 0, aux;
    FILE* archivo; // Se crea la variable puntero de tipo FILE

    if (archivo = fopen("setdatosedades.txt", "r")){ // Abriendo el archivo en modo lectura, si es True procede
    
        while(fscanf(archivo, "%d", &numeros[i]) != EOF){ // Mientras lea el archivo y guarde la posicion de numeros en i y sea diferente del End Of File sigue
            i++;
        }
        fclose(archivo); // Se cierra el archivo 
    }

    // Despues de leer el archivo de procede a implementar el algoritmo y a calcular su tiempo de ejecucion
    double tiempo = 0.0; // Variable para obtener el tiempo 
    clock_t begin = clock(); // Se inicializa el reloj

    // Algoritmo
    for(i = 1; i <= 2000; i ++) { // Se inicializa i en 1 para poder hacer la resta de indices 
        aux = numeros[i]; // Se guarda la posición actual en auxiliar para utilizarla posteriormente
        j = i - 1;
        
        while(j >= 0 && numeros[j] > aux) { // Mientras j sea mayor o igual a cero y numeros en la posicion j despues de la resta sea mayor a auxiliar, este while mueve los elementos que son mayores que el auxiliar a una posición adelantada de su posicion en ese momento
            numeros[j + 1] = numeros[j]; // Numeros en j + 1 se asigna a numeros en j
            j = j - 1; // Ahora se resta a j, j - 1 y se vuelve a revisar
        }
        numeros[j + 1] = aux; // Ahora en numeros en j + 1 va a ser igual a auxiliar, y se vuelve a repetir
    }

    clock_t end = clock(); // Termina el proceso de reloj
    tiempo += (double)(end - begin) / CLOCKS_PER_SEC; // Se calcula el tiempo final 

    // Se procede a imprimir el arreglo ordenado
    printf("Se procede a imprimir el arreglo ordenado: \n");
    for (i = 0; i < 2000; i++) {
        printf("%d\n", numeros[i]);
    }

    // Se procede a retornar el tiempo de ejecucion del algoritmo en especifico
    return tiempo;
}

double algoritmoSeleccion() {
    // Se lee el archivo
    int numeros[2000]; // Se crea el arreglo con el numero total de numeros
    int i = 0, j = 0, posicion = 0, aux = 0;
    FILE* archivo; // Se crea la variable puntero de tipo FILE

    if (archivo = fopen("setdatosedades.txt", "r")){ // Abriendo el archivo en modo lectura, si es True procede
    
        while (fscanf(archivo, "%d", &numeros[i]) != EOF){ // Mientras lea el archivo y guarde la posicion de numeros en i y sea diferente del End Of File sigue
            i++;
        }
        fclose(archivo); // Se cierra el archivo 
    }

    // Despues de leer el archivo de procede a implementar el algoritmo y a calcular su tiempo de ejecucion
    double tiempo = 0.0; // Variable para obtener el tiempo 
    clock_t begin = clock(); // Se inicializa el reloj

    // Algoritmo
    for(i = 0; i < 2000 - 1; i++){ // Comienza desde i con 0 hasta i menor a 1999
        posicion = i; // Se guarda la posicion de i en esta iteracion
        for(j = i + 1; j < 2000; j++){ // Para cada j de i + 1 menor a 2000 
            if(numeros[posicion] > numeros[j]){ // si numeros en la posicion es mayor a numeros en j
                posicion = j; // Entonces posicion se le asigna j
            }
        }
        if(posicion != j) { // si posicion es diferente a j
            aux = numeros[i]; // entonces a auxiliar se le asigna la posicion de i en la iteracion actual
            numeros[i] = numeros[posicion]; // a numeros en i se le asigna numeros en posicion
            numeros[posicion] = aux; // a numeros en posicion se le asigna el auxiliar previamente asignado
        }
    }

    clock_t end = clock(); // Termina el proceso de reloj
    tiempo += (double)(end - begin) / CLOCKS_PER_SEC; // Se calcula el tiempo final 

    // Se procede a imprimir el arreglo ordenado
    printf("Se procede a imprimir el arreglo ordenado: \n");
    for (i = 0; i < 2000; i++) {
        printf("%d\n", numeros[i]);
    }

    // Se procede a retornar el tiempo de ejecucion del algoritmo en especifico
    return tiempo;
}

int main(){
    double tiempo = 0.0, tiempo2 = 0.0, tiempo3 = 0.0;

    printf("Algoritmo burbuja\n");
    tiempo = algoritmoBurbuja();
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    printf("Algoritmo de seleccion\n");
    tiempo2 = algoritmoInsercion();
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    printf("Algoritmo de insercion\n");
    tiempo3 = algoritmoSeleccion();
    printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    printf("El tiempo que tardo el algoritmo burbuja fue: %f\n", tiempo);
    printf("El tiempo que tardo el algoritmo de seleccion fue: %f\n", tiempo2);
    printf("El tiempo que tardo el algoritmo de insercion fue: %f\n", tiempo3);
}