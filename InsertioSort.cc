 int ordenamiento_insercion(int a[],int n){
    int i,j,aux;
    for(i = 1; i < n ; i++){
        j = i;
        aux = a[i];
        while(j > 0 && aux < a[j-1]){
            a[j] = a[j-1];
            j--;
        }
        a[j] = aux;
    }
    std::cout<<"InsertionSort: " << std::endl ;
    for(int i=0; i<=n-1; i++){
        a[i] = rand()%100;
        std::cout<<"|"<< a[i]<<"|";
    }
    std::cout<< std::endl ;
    return *a;
}