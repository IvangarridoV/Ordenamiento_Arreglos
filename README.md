# Ordenamiento_Arreglos
Esta biblioteca tiene la función de ordenar números aleatorios con un tamaño definido por el usuario.
Se implementaron 3 métodos para la realización del ordenamiento.
Estos son: Bubble sort, Insertio sort y Selection sort.







Los comandos que utilizamos para la realización del proyecto fueron:

-New-Item (nombre de carpeta) -Type(Tipo) -Name (nombre) - Path (Dirección)

-git config -- user.email global "(correo)"(corre)"
-git config -- user.user global "(correo)"(nombre usuario)"
-git status 
-git clone
-git add "Nombredearchivo".cpp 
-git  commit -m"(Nombre)" // Este comando sirve para enviar el "archivo" al repositorio
-git pull
-git push
Biblioteca dinámica:
-g++ -shared .\src\Arreglo.cc -o orden.dll //Se comparte las funciones cc a un archivo dll
-g++ -shared .\src\bubblesort.cc -o orden.dll
-g++ -shared .\src\InsertioSort.cc -o orden.dll
-g++ -shared .\src\SelectionSort.cc -o orden.dll

-g++ main.cc orden.dll -o ordenamiento //Main toma las funciones de dll y se crea un ejecutable de ordenamiento
-g++ -c .\src\Arreglo.cc -o .\obj\Arreglo.o -I .\include //Se convierte en código fuente y se mueve a la carpeta obj
-g++ -c .\src\bubblesort.cc -o .\obj\bubblesort.o -I .\include// Este comando se utiliza para llamar la funcion bubblesort para convertirla en código fuente.
-g++ -shared .\src\bubblesort.cc -o orden.dll
-g++ -shared .\src\InsertioSort.cc -o orden.dll
-g++ -shared .\src\SelectionSort.cc -o orden.dll

-.\ordenamiento.exe  // Para ejecutar la biblioteca dinamica
-.\lib\dll\orden.dll // Se utiliza para acceder a la ruta de la biblioteca dinamica.

Manual para implementar una biblioteca de ordenamiento

Biblioteca estática:
    - Con el comando g++ -c <archivo> -o <archivo.o> -I <ruta> podemos convertir las funciones en código fuente y una vez implementada hace todas las funciones
     
    - Una vez implementado el comando anterior para todas las funciones de c++ se debe aplicar el siguiente comando:
     ar crs <archivo.lib> .\obj\*.o 
     Para crear tu biblioteca estática.

     - Para compilar la biblioteca se debe hacer uso del siguiente comando:
        g++ <archivo principal> -o <destino> -I <archivo> -L <ejecutable> -larith enlazando las bliblioteca

    - Y para ejecutar el programa se debe utilizar el siguiente comando:
    .\<nombre del ejecutable>.exe
     
Biblioteca dinámica:
    - Para tener una biblioteca .dll las funciones deben estar guardadas con el comando:
      g++ -shared <archivo> -o <nombre>.dll
    En donde se encarga de compartir las funciones en dll, debe aplicarse para todos los archivos con funciones.

    - g++ <archivo principal> <nombre del ejecutable>
    Este comando enlaza el main con la biblioteca dinamica en donde encuentra las funciones del archivo.

    - .\<nombre del ejecutable>.exe 
    Este comando ejecuta el archivo con la bilbioteca dinámica.
    
- Función bubblesort
    La función se ocupa para hacer el ordenamiento de burbuja que consiste en ir comparando ciertos números y si están desordenados los ira acomodando de izquierda a derecha. 
    Ejemplo: 75,19,23,76.
    Primero comparara el 75 y 19. Si el 75 es mayor que 19 se intercambiara la posición quedando 19, 75,23,76. Después la siguiente comparación será el 75 y 23. Si el 75 es mayor que 23 se intercambiaran de posición y quedara de la siguiente forma 19,23,75,76. Finalmente se hará la última comparación que es si el 75 es mayor que 76 se hace el cambio de posición. En este caso el 75 no es mayor que 76 así que el ordenamiento quedara 19,23,75,76.

- Función Quicksort
    La función se ocupa para hacer un ordenamiento rápido. Consiste ir dividiendo el arreglo en partes muy pequeñas hasta ordenarlo. por ejemplo: 5,10,3,2,7.
    Se tomará el pivot ósea el primer número que es 5 y después se ira comparando con los elementos del arreglo. Se hará una comparación de acuerdo a si son mayores que el pivot o menores que el pivot. Si el elemento es menor que el 5 se añade a la izquierda  si no se añade a la derecha. Se hará lo mismo que con resto de los números, quedando de la siguiente forma 3,2,5,10,7. Para ordenar los siguientes términos se hará lo mismo hasta ordenar todos los elementos quedando 2,3,5,7,10.

- Función InsertioSort
    Consiste en ir comparando dos elementos del arreglo y se empieza con los dos primeros. Si el elemento 0 es menor que el otro elemento 1 a comparar se pondrá  el elemento 0 de lado izquierdo y así sucesivamente.  Lo ira retirando el elemento de la lista y lo volverá a poner en la lista, pero esta vez en su posición correcta con respecto a una lista.
    Ejemplo:
    20,4,8,11,23,3,5(20<4) acomodado será 4,20,8,11,23,3,5 
    4,20,8,11,23,3,5(20<8) acomodado será 4,8,20,11,23,3,5
    4,8,20,11,23,3,5(20<11) acomodado 4,8,11,20,23,3,5
    4,8,11,20,23,3,5(20<23) acomodado 4,8,11,20,23,3,5
    4,8,11,20,23,3,5(23<3) acomodado 3,4,8,11,20,23,5 ( el insetio sort hace la comparación con todos los números, aunque nosotros no lo veamos por ello pasa el 3 hasta el principio)
    3,4,8,11,20,23,3,5(23<5) acomodado 3,4,5,8,11,20,23

- Función SelectionSort
    Ordenamiento por selección. Cosiste en encontrar el menor de todos los elementos del arreglo o vector e intercambiarlo con el que está en la primera posición. Luego el segundo mas pequeño y así sucesivamente hasta ordenarlo todo.
    4,3,1,6,5,2   Arreglo original.
    4,3,1,6,5,2   Empieza la función y encuentra al menor de todo el arreglo.
    1,4,3,6,5,2   Lo acomoda.
    1,4,3,6,5,2   Vuelve a buscar el segundo termino menor lo encuentra.
    1,2,4,3,6,5   Lo acomoda.
    1,2,4,3,6,5   Vuelve a buscar el tercer termino menor lo encuentra.
    1,2,3,4,6,5   Lo acomoda.
    1,2,3,4,6,5   Vuelve a buscar el segundo termino menor lo encuentra.
    1,2,3,4,6,5    Lo acomoda.
    1,2,3,4,6,5   Vuelve a buscar el segundo termino menor lo encuentra.
    1,2,3,4,5,6    Lo acomoda.    
