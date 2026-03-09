#include <iostream>
#include "header.h"

using namespace std;

/**
 * @brief Ordena o vetor com Bubble Sort.
 *
 * Percorre o vetor em múltiplas passadas, comparando pares adjacentes
 * e trocando quando estão fora de ordem. A cada passada, o maior valor
 * "sobe" para o final da parte não ordenada. Se uma passada não fizer
 * nenhuma troca, o algoritmo encerra antes (otimização).
 */
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
  // Controla cada passada do Bubble Sort (da 1ª até a penúltima posição).
  for (int step = 1; step < size; step++) {
    // Assume que nesta passada não houve troca ainda.
    hasChange = false; 

    // Percorre apenas a parte ainda não ordenada (o final já está correto).
    for (int element = 0; element < size-step; element++) {

      // Se o elemento atual for maior que o próximo, estão fora de ordem.
      if(vector[element] > vector[element+1]) {
        // Guarda temporariamente o valor da posição atual.
        aux = vector[element];
        // Move o próximo elemento (menor) para a posição atual.
        vector[element] = vector[element+1];
        // Coloca o valor guardado na próxima posição.
        vector[element+1] = aux;
        // Marca que houve troca nesta passada.
        hasChange = true; 
      }

    }

  // Se não houve troca, o vetor já está ordenado e o algoritmo para.
  if(!hasChange) break; 

  }
}

/**
 * @brief Ordena o vetor com Selection Sort.
 *
 * Para cada posição do vetor, procura o menor elemento no trecho ainda
 * não ordenado e o coloca na posição atual. Assim, a parte inicial do
 * vetor cresce já ordenada a cada iteração.
 */
void selection(int* vector, int size)
{
  // step: posição atual da fronteira ordenada; element: varredura;
  // lower: índice do menor elemento encontrado; aux: variável de troca.
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
    // armazena o menor valor encontrado nesta passada.
    aux = vector[lower];
    // inverte as posições.
    // coloca o valor da posição atual na antiga posição do menor.
    vector[lower] = vector[step];
    // coloca o menor valor na posição correta da parte ordenada.
    vector[step] = aux;
  }
}

/**
 * @brief Ordena o vetor com Insertion Sort.
 *
 * Considera que a parte inicial do vetor está ordenada e insere cada
 * novo elemento na posição correta dessa parte, deslocando elementos
 * conforme necessário. Nesta implementação, a condição `vector[element] < aux`
 * produz ordenação em ordem decrescente.
 */
void insertion(int* vector, int size)
{
  // step: índice do elemento a inserir; element: varredura para trás; aux: valor atual.
  int step, element, aux;

  // Começa do segundo elemento, pois o primeiro já é "subvetor ordenado".
  for(step = 1; step < size; step++){
    // Guarda o elemento que será inserido na parte ordenada.
    aux = vector[step];
    // Inicia a comparação pelo elemento imediatamente anterior.
    element = step - 1;
    // Enquanto houver elementos menores que aux, desloca para a direita.
    while (element >= 0 && vector[element] < aux) {
      // Desloca o elemento atual uma posição à frente.
      vector[element+1] = vector[element];
      // Anda uma posição para a esquerda.
      element--;
    }
    // Insere aux na posição correta encontrada.
    vector[element + 1] = aux;
  }

}
