#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <chrono>


using namespace std;
using namespace std::chrono;


int* copiarArreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}



void mostrarArreglo(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}



void insertionSort(int A[], int n) {
    for (int j = 1; j < n; j++) {
        int k = A[j];
        int i = j - 1;
 
        // Se mueven los elementos de A[0..i-1], que son
        // mayores que k, a una posición hacia la derecha
        // de su posicion actual
        while (i >= 0 && A[i] > k) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = k;
    }
}



void selectionSort(int A[], int n) {
    for (int j = 0; j < n-1; j++) {
        int menor = j;
 
        // Encuentra el elemento minimo del subarreglo
        // que no está ordenado
        for (int i = j+1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i;
            }
        }
        intercambiar (A, j, menor);
    }
}



void bubbleSort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
      
        // Los primeros i elementos ya estan ordenados
        for (int j = n-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                intercambiar(A, j, j-1);
            }
        }
    }
}



void combinar(int A[], int inicio, int medio, int fin) {
    int *aux = new int[fin - inicio + 1];
    int i = inicio;     // índice de la primera mitad
    int j = medio + 1;  // índice de la segunda mitad
    int h = 0;

    // Se recorren ambos subarreglos y se van combinando sus
    // elementos ordenadamente hasta que se haya recorrido
    // totalmente uno de ellos
    while ((i <= medio) && (j <= fin)) {
        if (A[i] <= A[j]) {
            aux[h] = A[i];
            i += 1;
        } else {
            aux[h] = A[j];
            j += 1;
        }
        h += 1;
    }

    // Si se copiaron todos los elementos de la primera mitad,
    // se copia el resto de la segunda mitad
    if (i > medio) {
        while (j <= fin) {
            aux[h] = A[j];
            j += 1;
            h += 1;
        }
    } // Si no, se copia el resto de la primera mitad
    else {
        while (i <= medio) {
            aux[h] = A[i];
            i += 1;
            h += 1;
        }
    }
    
    h = 0;
    for (int k = inicio; k <= fin; k++) {
        A[k] = aux[h];
        h += 1;
    }
    delete [] aux;
}

void mergeSort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        mergeSort(A, inicio, medio);
        mergeSort(A, medio + 1, fin);
        combinar(A, inicio, medio, fin);
    }
}



int particionar(int A[], int p, int r) {
    // A[r] es el registro elegido cuya llave será el pivote
    int pivote = A[r];
    
    // Indica el índice del último registro cuyo valor
    // es menor a pivote
    int ultimo = p - 1;

    // Se agrupan los elementos menores a pivote en las primeras
    // posiciones de A
    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    // Y se mueve al pivote a su posición correcta
    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = particionar(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}



void experimentos(int tam, int reps, bool is, bool ss, bool bs, bool ms, bool qs) {

    int TAM_ARREGLO = tam;
    int RANGO_MAX = 10 * TAM_ARREGLO;
    int REPETICIONES = reps;
    double tpromis = 0.0;
    double tpromss = 0.0;
    double tprombs = 0.0;
    double tpromms = 0.0;
    double tpromqs = 0.0;

    srand((unsigned) time(0));
    for (int i = 0; i < REPETICIONES; i++) {
        cout << "*** REPETICION " << i+1 << " ***" << endl;
        int *A = new int[TAM_ARREGLO];

        // Arreglo pseudoaleatorio
        high_resolution_clock::time_point start = high_resolution_clock::now();
        cout << "Creando arreglo pseudoaleatorio de tamaño " << TAM_ARREGLO << "... ";
        for (int i = 0; i < TAM_ARREGLO; i++) {
            int x = rand() % RANGO_MAX;
            A[i] = x;
        }
        cout << "Creado. ";
        high_resolution_clock::time_point stop = high_resolution_clock::now();
        duration<double> durarr = duration_cast<duration<double> >(stop - start);
        cout << "Tiempo: " << durarr.count() << endl;

        int *aux;
        if (is) {
            aux = copiarArreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con INSERTION SORT... " << endl;
            start = high_resolution_clock::now();
            insertionSort(aux, TAM_ARREGLO);
            stop = high_resolution_clock::now();
            cout << "\tOrdenado. ";
            duration<double> duris = duration_cast<duration<double> >(stop - start);
            cout << "Tiempo: " << duris.count() << endl;
            tpromis = tpromis + duris.count();
            delete [] aux;
        }

        if (ss) {
            aux = copiarArreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con SELECTION SORT... " << endl;
            start = high_resolution_clock::now();
            selectionSort(aux, TAM_ARREGLO);
            stop = high_resolution_clock::now();
            cout << "\tOrdenado. ";
            duration<double> durss = duration_cast<duration<double> >(stop - start);
            cout << "Tiempo: " << durss.count() << endl;
            tpromss = tpromss + durss.count();
            delete [] aux;
        }

        if (bs) {
            aux = copiarArreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con BUBBLE SORT... " << endl;
            start = high_resolution_clock::now();
            bubbleSort(aux, TAM_ARREGLO);
            stop = high_resolution_clock::now();
            cout << "\tOrdenado. ";
            duration<double> durbs = duration_cast<duration<double> >(stop - start);
            cout << "Tiempo: " << durbs.count() << endl;
            tprombs = tprombs + durbs.count();
            delete [] aux;
        }

        if (ms) {
            aux = copiarArreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con MERGE SORT... " << endl;
            start = high_resolution_clock::now();
            mergeSort(aux, 0, TAM_ARREGLO-1);
            stop = high_resolution_clock::now();
            cout << "\tOrdenado. ";
            duration<double> durms = duration_cast<duration<double> >(stop - start);
            cout << "Tiempo: " << durms.count() << endl;
            tpromms = tpromms + durms.count();
            delete [] aux;
        }

        if (qs) {
            aux = copiarArreglo(A, TAM_ARREGLO);
            cout << "Iniciando ordenamiento con QUICKSORT... " << endl;
            start = high_resolution_clock::now();
            quickSort(aux, 0, TAM_ARREGLO-1);
            stop = high_resolution_clock::now();
            cout << "\tOrdenado. ";
            duration<double> durqs = duration_cast<duration<double> >(stop - start);
            cout << "Tiempo: " << durqs.count() << endl << endl;
            tpromqs = tpromqs + durqs.count();
            delete [] aux;
        }

        delete [] A;
    }
    tpromis = tpromis / REPETICIONES;
    tpromss = tpromss / REPETICIONES;
    tprombs = tprombs / REPETICIONES;
    tpromms = tpromms / REPETICIONES;
    tpromqs = tpromqs / REPETICIONES;
    cout << "*** TIEMPO PROMEDIO ***" << endl;
    if (is) {
        cout << "Insertion sort: " << tpromis << endl;
    }
    if (ss) {
        cout << "Selection sort: " << tpromss << endl;
    }
    if (bs) {
        cout << "Bubble sort: " << tprombs << endl;
    }
    if (ms) {
        cout << "Merge sort: " << tpromms << endl;
    }
    if (qs) {
        cout << "Quicksort: " << tpromqs << endl << endl;
    }
}



bool incluirAlgoritmo(string listaAlgs, char alg) {
    size_t incluir = listaAlgs.find(alg);
    return incluir != string::npos;
}


int main(int argc, char * argv[]) {
    if (argc != 4) {
        cout << "Sintaxis: ordenamiento <tamaño_arreglo> <repeticiones> <lista_algoritmos>" << endl;
        cout << "Algoritmos:" << endl;
        cout << "i: insertion sort" << endl;
        cout << "s: selection sort" << endl;
        cout << "b: bubblesort" << endl;
        cout << "m: merge sort" << endl;
        cout << "q: quicksort" << endl;
    } else {
        bool is = incluirAlgoritmo(argv[3], 'i');
        bool ss = incluirAlgoritmo(argv[3], 's');
        bool bs = incluirAlgoritmo(argv[3], 'b');
        bool ms = incluirAlgoritmo(argv[3], 'm');
        bool qs = incluirAlgoritmo(argv[3], 'q');
        experimentos(atoi(argv[1]), atoi(argv[2]), is, ss, bs, ms, qs);
    }
    return EXIT_SUCCESS;
}
