#include <ostream>
#include <iostream> 

int ordenamiento_seleccion(int a[], int n){
    int indiceMenor;
    for(int i=0; i<n-1; i++){
        indiceMenor=i;
        for(int j=i+1 ; j<n ; j++){
            if(a[j] < a[indiceMenor]){
                indiceMenor = j;
            }
        }
        if(i != indiceMenor){
            int aux = a[i];
            a[i]=a[indiceMenor];
            a[indiceMenor]=aux;
        }
    }
    std::cout<<"Selection sort: " << std::endl; 
    for(int i=0; i<=n-1; i++){
        std::cout<<"|"<< a[i]<<"|";
    }
    std::cout<< std::endl ;
    return *a;
}