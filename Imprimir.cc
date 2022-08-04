
void print_array(int a[], int n){
    std::cout<<"Arreglo ordenado"<<std::endl;
    for(int i=0; i<=n-1; i++){
        a[i] = rand()%100;
        std::cout<<"|"<< a[i]<<"|";
    }
    std::cout<<"impresion finalizada" << std::endl;
}
