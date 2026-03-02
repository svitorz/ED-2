#ifndef EFFICIENT_SORT
#define EFFICIENT_SORT

void mergeSort(int* vector, int left, int right);
void merge(int* vector, int left,int mid, int right);
void quick(int* vector, int left, int right);
void shell(int* vector, int size);
int particiona(int* vector, int left, int right);

#endif // !EFFICIENT_SORT
