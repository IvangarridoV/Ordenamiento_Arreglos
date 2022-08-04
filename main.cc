#include "iostream" 
#include <stdlib.h>
#include "InsertioSort.cc"
#include "bubblesort.cc"
#include "SelectionSort.cc"
#include "Imprimir.cc"
#include <time.h>
#include "Arreglo.cc" 


using namespace std;



int main(){
    
    int tam;
    cout << "Tamanio: ";
    cin>>tam;
    int pive[tam];
    
    crearArreglo(pive, tam);
    ordenamiento_insercion(pive, tam);
    ordenamiento_burbuja(pive,tam);
    ordenamiento_seleccion(pive,tam);
    //print_array(pive,tam);
     
    return 0;
}
