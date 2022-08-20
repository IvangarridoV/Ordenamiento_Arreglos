#include <ostream>
#include <iostream>
int ordenamiento_burbuja(int a[], int n){  // a= [7,5,2,9] //a= [5,2,7,9]
    int interruptor=1; //n=4

    for(int pasada = 0; pasada < n-1 && interruptor; pasada++){ //pasada=1//pasada=2
        interruptor =0;
        //desde j=0 hasta j menor 4-1-1=2
        for(int j=0 ; j < n-pasada-1 ; j++){ //j=0 //j=1//j=2 /////con pasada=2 4-2-1=1
            if(a[j]>a[j+1]){ //5>2//5>7//   ///2>5
                int aux;
                interruptor=1;
                aux= a[j]; // aux=5
                a[j]=a[j+1];//a[0]=2
                a[j+1]=aux;//a[1]=5...a= [2,5,7,9]
            }
        }
    } 
    std::cout<<"Bubblesort: " << std::endl;
    for(int i=0; i<=n-1; i++){
        std::cout<<"|"<< a[i]<<"|";
    } 
    std::cout<< std::endl ;
    return *a;  
}