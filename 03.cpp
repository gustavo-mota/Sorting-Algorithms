#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int *arrayInitializer(int qtd)
{
    int *lista = new int[qtd];
    srand((unsigned)time(0));
    for (int i = 0; i < qtd; i++)
    {
        // lista[i] = (rand() % 35) + 1;
        lista[i] = rand();
    }
    return lista;
}

void merge(int *lista, int inicio, int meio, int fim)
{
    // const int aux1 = meio - inicio + 1;
    int aux1 = meio - inicio;
    int aux2 = fim - meio;
    int *left = new int[aux1];
    int *right = new int[aux2];

    for (int i = 0; i < aux1; i++)
    {
        left[i] = lista[inicio + i];
    }
    for (int j = 0; j < aux2; j++)
    {
        right[j] = lista[meio + j];
    }
    int idxLeft = 0;
    int idxRight = 0;
    int idxMerged = inicio;

    while (idxLeft < aux1 && idxRight < aux2)
    {
        if (left[idxLeft] <= right[idxRight])
        {
            lista[idxMerged] = left[idxLeft];
            idxLeft = idxLeft + 1;
        }
        else
        {
            lista[idxMerged] = right[idxRight];
            idxRight = idxRight + 1;
        }
        idxMerged = idxMerged + 1;
    }

    while (idxLeft < aux1)
    {
        lista[idxMerged] = left[idxLeft];
        idxMerged++;
        idxLeft++;
    }

    while (idxRight < aux2)
    {
        lista[idxMerged] = right[idxRight];
        idxMerged++;
        idxRight++;
    }
}

void merge_sort(int *lista, int inicio, int fim)
{
    if (fim - inicio > 1)
    {
        int meio = (inicio + fim) / 2;
        merge_sort(lista, inicio, meio);
        merge_sort(lista, meio + 1, fim);
        merge(lista, inicio, meio, fim + 1);
    }
}

int *sortedArrayGenerator(int qtd)
{
    int *lista = new int[qtd];
    for (int i = 0; i < qtd; i++)
    {
        lista[i] = i;
    }
    return lista;
}

int main()
{
    int *lista;
    int size = 10;
    lista = arrayInitializer(size);
    // lista = sortedArrayGenerator(size);
    for (int i = 0; i < size; i++)
    {
        cout << lista[i] << ' ';
    }
    cout << '\n'
         << endl;
    merge_sort(lista, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << lista[i] << ' ';
    }
    return 0;
}