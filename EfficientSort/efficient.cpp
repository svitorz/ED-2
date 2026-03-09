#include <iostream>
#include "header.h"

using namespace std;

void shell(int *vetor, int size)
{
  int i, j, aux, gap;
  for (gap=size/2; gap>0; gap/=2){
    for (i=gap; i<size; i++){
      aux = vetor[i];
      j=i;
      while (j>=gap && vetor[j-gap]>aux){
        vetor[j] = vetor[j-gap];
        j-=gap;
      }
      vetor[j] = aux;
    }
  }
}

void mergeSort(int *vetor, int start, int end)
{
  if (start >= end) return;

  int mid = start + (end - start) / 2;
  mergeSort(vetor, start, mid);
  mergeSort(vetor, mid + 1, end);
  merge(vetor, start, mid, end);
}

void merge(int* vetor, int start, int mid, int end)
{
  int size = end - start + 1;
  int *temp = new int[size];

  int p1 = start;
  int p2 = mid + 1;
  int fim1 = 0;
  int fim2 = 0;

  for (int i = 0; i < size; i++) {
    if (!fim1 && !fim2) {
      if (vetor[p1] < vetor[p2]) {
        temp[i] = vetor[p1++];
      } else {
        temp[i] = vetor[p2++];
      }

      if (p1 > mid) fim1 = 1;
      if (p2 > end) fim2 = 1;
    } else {
      if (!fim1) {
        temp[i] = vetor[p1++];
      } else {
        temp[i] = vetor[p2++];
      }
    }
  }

  for (int j = 0, k = start; j < size; j++, k++) {
    vetor[k] = temp[j];
  }

  delete[] temp;
}

void quick(int* vetor, int start, int end)
{
  int pivot;
  if (end > start) {
    pivot = particiona(vetor, start, end);
    quick(vetor, start, pivot - 1);
    quick(vetor, pivot+1, end);
  }
}

int particiona(int* vetor, int start, int end)
{
  int left, right, pivot, aux;

  left = start;
  right = end;
  pivot = vetor[start];

  while (left < right) {
    while(left <= end && vetor[left] <= pivot)
    {
      left++;
    }

    while (right >= 0 && vetor[right] > pivot) {
      right--;
    }

    if (left < right) {
      aux = vetor[left];
      vetor[left] = vetor[right];
      vetor[right] = aux;
    }
  }
  vetor[start] = vetor[right];
  vetor[right] = pivot;
  return right;
}
