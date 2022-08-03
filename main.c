#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int crearArreglo(int arreglo[],int tam){
    int i;

    srand(time(NULL));
    tam = tam-1;
    printf("Arreglo original: \n\n");
    for(i=0; i<=tam; i++){
        arreglo[i]=rand()%100;
        printf("|%d|", arreglo[i]);        
    }
    return *arreglo;
}

int ordenamiento(int arreglo[], int tam){
    int k=0, c, aux;
 
    for (c=0; c<=tam; c++){
        for(k=0; k<c; k++){
            if(arreglo[k]>arreglo[c]){
                aux=arreglo[c];
                arreglo[c]=arreglo[k];
                arreglo[k]=aux;
                printf("\nCambio: %d %d", arreglo[k], arreglo[c]);
            }
        }
    }
    return *arreglo;
}

int mostrarOrden(int arreglo[],int tam){
    int i;

    printf("\n\nArreglo ordenado: \n\n");
    for(i=0; i<=tam-1; i++){
        printf("|%d|", arreglo[i]);
    }
    return *arreglo;
}

int main(){
    int tam;
    printf("Tamanio: ");
    scanf("%d", &tam);
    int pive[tam];

    crearArreglo(pive,tam);
    ordenamiento(pive,tam);
    mostrarOrden(pive,tam);

    return 0;
}
