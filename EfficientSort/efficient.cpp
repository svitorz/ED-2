#include <iostream>
#include "header.h"

using namespace std;

/**
 * @brief Ordena o vetor com Shell Sort.
 *
 * Generaliza o Insertion Sort usando "gaps" (saltos) maiores no início,
 * reduzindo gradualmente até 1. Isso antecipa movimentações de elementos
 * distantes e tende a reduzir o número total de deslocamentos.
 */
void shell(int *vetor, int size)
{
  // i: índice de varredura; j: índice para deslocamentos; aux: valor atual; gap: distância entre comparações.
  int i, j, aux, gap;
  // Começa com gap = metade do vetor e reduz pela metade até chegar a 1.
  for (gap=size/2; gap>0; gap/=2){
    // Percorre os elementos a partir do gap atual.
    for (i=gap; i<size; i++){
      // Guarda o elemento que será inserido na subsequência do gap.
      aux = vetor[i];
      // Inicia comparações na posição atual.
      j=i;
      // Desloca elementos maiores que aux dentro da mesma subsequência.
      while (j>=gap && vetor[j-gap]>aux){
        // Move o elemento anterior (com passo gap) para frente.
        vetor[j] = vetor[j-gap];
        // Retrocede uma posição de gap.
        j-=gap;
      }
      // Coloca aux na posição correta da subsequência.
      vetor[j] = aux;
    }
  }
}

/**
 * @brief Ordena o vetor com Merge Sort (divisão e conquista).
 *
 * Divide recursivamente o intervalo em duas metades até sobrar apenas
 * um elemento por intervalo e, em seguida, intercala as metades já
 * ordenadas usando a função `merge()`.
 */
void mergeSort(int *vetor, int start, int end)
{
  // Caso base: intervalo vazio ou com um único elemento já está ordenado.
  if (start >= end) return;

  // Calcula o meio do intervalo evitando overflow em (start + end).
  int mid = start + (end - start) / 2;
  // Ordena recursivamente a metade esquerda.
  mergeSort(vetor, start, mid);
  // Ordena recursivamente a metade direita.
  mergeSort(vetor, mid + 1, end);
  // Intercala as duas metades ordenadas em um único trecho ordenado.
  merge(vetor, start, mid, end);
}

/**
 * @brief Intercala dois subvetores ordenados em um único trecho ordenado.
 *
 * Recebe os intervalos [start..mid] e [mid+1..end], ambos já ordenados,
 * e os combina em ordem dentro de um vetor temporário. Ao final, copia
 * o resultado de volta para o vetor original.
 */
void merge(int* vetor, int start, int mid, int end)
{
  // Tamanho total do intervalo que será mesclado.
  int size = end - start + 1;
  // Aloca vetor temporário para armazenar a intercalação.
  int *temp = new int[size];

  // Ponteiro para início da primeira metade.
  int p1 = start;
  // Ponteiro para início da segunda metade.
  int p2 = mid + 1;
  // Flags que indicam se cada metade chegou ao fim.
  int fim1 = 0;
  int fim2 = 0;

  // Preenche o temporário com os menores elementos disponíveis entre as duas metades.
  for (int i = 0; i < size; i++) {
    // Se ainda há elementos nas duas metades, compara os dois ponteiros.
    if (!fim1 && !fim2) {
      // Se o elemento da esquerda for menor, copia ele e avança p1.
      if (vetor[p1] < vetor[p2]) {
        temp[i] = vetor[p1++];
      } else {
        // Caso contrário, copia da direita e avança p2.
        temp[i] = vetor[p2++];
      }

      // Marca fim da primeira metade quando p1 ultrapassa mid.
      if (p1 > mid) fim1 = 1;
      // Marca fim da segunda metade quando p2 ultrapassa end.
      if (p2 > end) fim2 = 1;
    } else {
      // Se uma metade acabou, copia o restante da outra metade.
      if (!fim1) {
        temp[i] = vetor[p1++];
      } else {
        temp[i] = vetor[p2++];
      }
    }
  }

  // Copia do temporário para o intervalo original [start..end].
  for (int j = 0, k = start; j < size; j++, k++) {
    vetor[k] = temp[j];
  }

  // Libera a memória alocada para o vetor temporário.
  delete[] temp;
}

/**
 * @brief Ordena o vetor com Quick Sort.
 *
 * Escolhe um pivô, particiona o vetor em duas partes (menores/maiores
 * em relação ao pivô) e ordena recursivamente cada partição.
 */
void quick(int* vetor, int start, int end)
{
  // Índice final onde o pivô ficará após a partição.
  int pivot;
  // Só processa quando há pelo menos dois elementos no intervalo.
  if (end > start) {
    // Reorganiza o intervalo e obtém a posição final do pivô.
    pivot = particiona(vetor, start, end);
    // Ordena recursivamente a parte à esquerda do pivô.
    quick(vetor, start, pivot - 1);
    // Ordena recursivamente a parte à direita do pivô.
    quick(vetor, pivot+1, end);
  }
}

/**
 * @brief Particiona o vetor para o Quick Sort.
 *
 * Usa o primeiro elemento como pivô e move ponteiros da esquerda e
 * direita em busca de elementos fora da partição correta. Quando os
 * ponteiros se cruzam, coloca o pivô em sua posição final e retorna
 * seu índice.
 */
int particiona(int* vetor, int start, int end)
{
  // left e right percorrem o intervalo; pivot guarda o valor pivô; aux auxilia na troca.
  int left, right, pivot, aux;

  // Inicia ponteiro esquerdo no começo do intervalo.
  left = start;
  // Inicia ponteiro direito no fim do intervalo.
  right = end;
  // Define o pivô como o primeiro elemento do intervalo.
  pivot = vetor[start];

  // Continua enquanto os ponteiros não se cruzarem.
  while (left < right) {
    // Avança left enquanto encontrar valores menores ou iguais ao pivô.
    while(left <= end && vetor[left] <= pivot)
    {
      left++;
    }

    // Recuar right enquanto encontrar valores maiores que o pivô.
    while (right >= 0 && vetor[right] > pivot) {
      right--;
    }

    // Se ainda não cruzou, troca os elementos fora de posição.
    if (left < right) {
      aux = vetor[left];
      vetor[left] = vetor[right];
      vetor[right] = aux;
    }
  }
  // Coloca o pivô na posição definitiva da partição.
  vetor[start] = vetor[right];
  // Grava o valor do pivô na posição final encontrada.
  vetor[right] = pivot;
  // Retorna o índice final do pivô.
  return right;
}
