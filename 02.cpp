#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int *arrayInitializer(int qtd)
{
    int *lista = new int[qtd];
    srand((unsigned)time(NULL));
    for (int i = 0; i < qtd; i++)
    {
        lista[i] = rand();
    }
    return lista;
}

int qs_partition(int *lista, int initer, int fim)
{
    int pivot = lista[fim];
    int aux;
    int i = initer - 1;
    for (int j = initer; j <= fim - 1; j++)
    {
        if (lista[j] < pivot)
        {
            i = i + 1;
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }
    i++;
    aux = lista[i];
    lista[i] = lista[fim];
    lista[fim] = aux;
    return i;
}

int quick_sort(int *lista, int initer, int size)
{
    int p;
    if (initer < size)
    {
        p = qs_partition(lista, initer, size);
        quick_sort(lista, initer, p - 1);
        quick_sort(lista, p + 1, size);
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
    quick_sort(lista, 0, size - 1);
    cout << '-' << endl;
    for (int i = 0; i < size; i++)
    {
        cout << lista[i] << ' ';
    }
    return 0;
}