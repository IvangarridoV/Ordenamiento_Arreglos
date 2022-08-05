
int crearArreglo(int arreglo[], int tam){
    //srand(time(NULL));
    std::cout<<"Arreglo original:\n";
    for(int i=0; i<=tam-1; i++){
        arreglo[i] = rand()%100;
        std::cout<<"|"<< arreglo[i]<<"|";
    }
    std::cout<<std::endl;
    return *arreglo;
}
