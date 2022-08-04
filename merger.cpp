#include "iostream"
#include <stdlib.h> 


function mergeSort(arr) {
  /* Metodo recursivo */
  if (arr.length === 1) {
    /* recursividad termina cuando la longitud del arreglo es 1
    	(Ya no hay nada que ordenar)
    */
    return arr
  }

  const mitad = Math.floor(arr.length / 2) // obtenemos la mitad del arreglo redondeando hacia abajo.
  const izquierda = arr.slice(0, mitad) // Elementos del lado izquierdo
  const derecha = arr.slice(mitad) // Elementos del lado derecho

  return merge(
    mergeSort(izquierda),
    mergeSort(derecha)
  )
}

// compara ambos arreglos y devuelve la union de los resultados
function merge (left, right) {
  
  let result = []
  let indexLeft = 0
  let indexRight = 0

  while (indexLeft < left.length && indexRight < right.length) {
    
    if (left[indexLeft] < right[indexRight]) {
      result.push(left[indexLeft])
      indexLeft++
    } else {
      result.push(right[indexRight])
      indexRight++
    }
  }

  return result.concat(left.slice(indexLeft)).concat(right.slice(indexRight))
}