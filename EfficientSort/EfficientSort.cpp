#include <iostream>
#include "header.h"

using namespace std;

/**
 * Função que inicia com um gap grande (metade do tamanho do vetor) e 
 * vai diminuindo o valor do gap progressivamente até que ele seja 1. Para
 * cada valor de gap, o algoritmo realiza uma ordenação por inserção, mas
 * de forma que os elementos com um intervalo de gap entre eles sejam
 * comparados e trocados.
 * */
void shell(int* vector, int size)
{
  int i, j, aux, gap;
  for (gap = size/2; gap > 0; gap /= 2) {
    for (i = gap; i < size; i++) {
        aux = vector[i];
        j=i;
        
        while (j>= gap && vector[j-gap] > aux) {
          vector[j] = vector[j - gap];
          j -= gap;
        }
        vector[j] = aux;
    }    
  }
}

void mergeSort(int* vector, int left, int right)
{
  if (left >= right) return;

  int mid = left + (right - left) / 2; 

  mergeSort(vector, left, mid);
  mergeSort(vector, mid + 1, right);
  merge(vector, left, mid, right);
}

void merge(int* vector, int left, int mid, int right)
{
  int *temp, size;

  size = right - left + 1;

  temp = new int [size];

  int p1, p2, i, j, fim1 = 0, fim2 = 0;

  p1 = left; p2 = mid + 1; 

  if (temp != NULL) {
    for (i=0;  i < tam; i++) {
      if (fim1 == 0 && fim2 == 0) {
        if (vector[p1] < vector[p2]) {
            temp[i] = vector[p1];
            p1++;
        } else {
            temp[i] = V[p2];
            p2++;
        }
        if(p1 > mid) fim1=1;
        if(p2 > right) fim2 = 1;
      } else {
        if (fim1 == 0) {
            temp[i] = vector[p1++]; 
        } else {
          temp[i] = V[p2++];
        }
      }
    }
    for (j = 0, k = left; j < size; j++, k++) {
      vector[k] = temp[j];
    }
  }
  delete[] temp;
}

void quick(int* vector, int left, int right)
{
  int pivo;
  if (right > left) {
    pivo = particiona(vector, left, right);
    quickSort(vector, left, pivo - 1);
    quickSort(vector, pivo + 1, right);
  }
}

int particiona(int* vector, int left, int right)
{

}
