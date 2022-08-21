#include <iostream> 
#include <stdlib.h>
#include ".\src\InsertioSort.cc"
#include ".\src\bubblesort.cc"
#include ".\src\SelectionSort.cc"
#include <time.h>
#include ".\src\Arreglo.cc"
#include <cstddef>
#include <ostream>


using namespace std;


int main(){
    int n = 0;
    do{ 
    int tam;
    cout << "Tamanio: ";
    cin>>tam;
    int pive[tam];
    
    crearArreglo(pive, tam);
    ordenamiento_insercion(pive, tam);
    ordenamiento_burbuja(pive,tam);
    ordenamiento_seleccion(pive,tam);
    cout <<"Quieres continuar? 0 si, cualquier otro numero no:"  ;  
    cin>>n;
    }while(n == 0);
    return 0;
}