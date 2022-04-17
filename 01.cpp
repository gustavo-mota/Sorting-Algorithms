#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int *arrayInitializer(int qtd)
{
    // const int size = qtd;
    int *lista = new int[qtd];
    srand((unsigned)time(NULL));
    for (int i = 0; i < qtd; i++)
    {
        lista[i] = rand();
    }
    return lista;
}

int selection_sort(int *lista, int size)
{
    for (int j = 0; j < size; ++j)
    {
        int minIdx = j;
        for (int i = j; i < size; ++i)
        {
            if (lista[i] < lista[minIdx])
            {
                minIdx = i;
            }
        }
        if (lista[j] > lista[minIdx])
        {
            int aux = lista[j];
            lista[j] = lista[minIdx];
            lista[minIdx] = aux;
        }
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
    // lista = arrayInitializer(size);
    lista = sortedArrayGenerator(size);
    for (int i = 0; i < size; i++)
    {
        cout << lista[i] << ' ';
    }
    cout << '\n'
         << endl;
    selection_sort(lista, size);
    for (int i = 0; i < size; i++)
    {
        cout << lista[i] << ' ';
    }
    return 0;
}