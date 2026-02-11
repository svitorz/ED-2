#include <iostream>
#include "header.h"

using namespace std;

void bubble(int* vector, int size)
{
  //verifica se houve trocas no último loop
  bool hasChange; 

  //auxiliar para realizar trocas
  int aux;

  /**
   *  @var step numero de loops necessarios para percorrer todo o vetor
   *
   * */
  for (int step = 1; step < size; step++) {
    hasChange = false; 

    for (int element = 0; element < size-step; element++) {

      if(vector[element] > vector[element+1]) {
        aux = vector[element];
        vector[element] = vector[element+1];
        vector[element+1] = aux;
        hasChange = true; 
      }

    }

  if(!hasChange) break; 

  }
}

void selection(int* vector, int size)
{
  int step, element, lower, aux;

  //percorre o vetor
  for (step = 0; step < size-1; step++) { //vai até penúltima posição
    // define o menor valor como o atual                                       
    lower = step;
    for (element = step+1; element < size; element++) { //element adjacente a step 
      // busca por um elemento menor                                                    
      if(vector[element] < vector[lower])
        // se encontrar, define a variavel lower com ele.
        lower = element;
    }
    // quando nenhum valor menor for encontrado, o aux se torna o menor 
    aux = vector[lower];
    // inverte as posições.
    vector[lower] = vector[step];
    vector[step] = aux;
  }
}

void insertion(int* vector, int size)
{
  int step, element, aux;

  for(step = 1; step < size; step++){
    aux = vector[step];
    element = step - 1;
    while (element >= 0 && vector[element] < aux) {
      vector[element+1] = vector[element];
      element--;
    }
    vector[element + 1] = aux;
  }

}
