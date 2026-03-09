#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "header.h"

using namespace std;

void mostrarVetor(const vector<int>& vetor)
{
  if (vetor.empty()) {
    cout << "Vetor vazio.\n";
    return;
  }

  cout << "[ ";
  for (size_t i = 0; i < vetor.size(); i++) {
    cout << vetor[i];
    if (i + 1 < vetor.size()) cout << ", ";
  }
  cout << " ]\n";
}

int main () {
  srand(static_cast<unsigned int>(time(nullptr)));

  vector<int> vetor;
  int opcao;

  do {
    cout << "\n===== MENU =====\n";
    cout << "1 - Criar vetor manualmente\n";
    cout << "2 - Criar vetor aleatorio\n";
    cout << "3 - Mostrar vetor atual\n";
    cout << "4 - Ordenar com Shell Sort\n";
    cout << "5 - Ordenar com Merge Sort\n";
    cout << "6 - Ordenar com Quick Sort\n";
    cout << "0 - Sair\n";
    cout << "Escolha: ";
    cin >> opcao;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(10000, '\n');
      cout << "Opcao invalida.\n";
      continue;
    }

    if (opcao == 1) {
      int n;
      cout << "Tamanho do vetor: ";
      cin >> n;

      if (n <= 0) {
        cout << "Tamanho invalido.\n";
        continue;
      }

      vetor.resize(n);
      for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> vetor[i];
      }

      cout << "Vetor criado com sucesso.\n";
    }
    else if (opcao == 2) {
      int n, minimo, maximo;
      cout << "Tamanho do vetor: ";
      cin >> n;
      cout << "Valor minimo: ";
      cin >> minimo;
      cout << "Valor maximo: ";
      cin >> maximo;

      if (n <= 0 || minimo > maximo) {
        cout << "Parametros invalidos.\n";
        continue;
      }

      vetor.resize(n);
      for (int i = 0; i < n; i++) {
        vetor[i] = minimo + (rand() % (maximo - minimo + 1));
      }

      cout << "Vetor aleatorio criado com sucesso.\n";
    }
    else if (opcao == 3) {
      mostrarVetor(vetor);
    }
    else if (opcao == 4) {
      if (vetor.empty()) {
        cout << "Crie um vetor antes de ordenar.\n";
      } else {
        shell(vetor.data(), static_cast<int>(vetor.size()));
        cout << "Vetor ordenado com Shell Sort.\n";
        mostrarVetor(vetor);
      }
    }
    else if (opcao == 5) {
      if (vetor.empty()) {
        cout << "Crie um vetor antes de ordenar.\n";
      } else {
        mergeSort(vetor.data(), 0, static_cast<int>(vetor.size()) - 1);
        cout << "Vetor ordenado com Merge Sort.\n";
        mostrarVetor(vetor);
      }
    }
    else if (opcao == 6) {
      if (vetor.empty()) {
        cout << "Crie um vetor antes de ordenar.\n";
      } else {
        quick(vetor.data(), 0, static_cast<int>(vetor.size()) - 1);
        cout << "Vetor ordenado com Quick Sort.\n";
        mostrarVetor(vetor);
      }
    }
    else if (opcao != 0) {
      cout << "Opcao invalida.\n";
    }

  } while (opcao != 0);

  cout << "Programa encerrado.\n";
  return 0;
}
