#include "pch.h"
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include <conio.h>
#include <vector>

using namespace System;
using namespace std; 

void printArray(int arr[], int longitud)
{
    for (int i = 0; i < longitud; i++) {
        cout << arr[i] << " " << endl;
    }
}
void Swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void algoritmoFisherYates(int arr[], int longitud) { // Complejidad O(n)

    for (int i = longitud -1; i > 0; i--)
    {
        int j = (rand() % (i + 1)); 
        Swap(&arr[j], &arr[i]);
    }   
}
void OrdenamientoIntercambio(int arr[], int longitud) {
    for (int i = 0; i < longitud-1; i++)
    {
        for (int  j = i+1; j < longitud; j++)
        {
            if (arr[i] > arr[j]) {
                int aux = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = aux; 
            }
        }
    }
}
void Burbuja(int arr[], int longitud) {
    bool ordenado; 

    for (int i = 0; i < longitud - 1; i++)
    {
        ordenado = true; 
        for (int j = 0; j < longitud-(i+1); j++)
        {
            if (arr[j] > arr[j+1]) {
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
                ordenado = false; 
            }
        }
        if (ordenado) {
            break; 
        }
    }
}
void OrdenamientoSeleccion(int arr[], int longitud) {
    int k, menor; 

    for (int i = 0; i < longitud - 1; i++)
    {
        k = i; 
        menor = arr[i]; 
        for (int j = i + 1; j < longitud; j++)
        {
            if (arr[j] < menor) {
                menor = arr[j]; 
                k = j; 
            }
        }
        arr[k] = arr[i]; 
        arr[i] = menor; 
    }
}
void OrdenaminetoInsercion(int arr[], int longitud) {
    int aux, k; 
    for (int i = 1; i < longitud; i++)
    {
        aux = arr[i]; 
        k = i - 1; 
        while (k>=0 && aux<arr[k]){
            arr[k + 1] = arr[k]; 
            k--; 
        }
        arr[k + 1] = aux; 
    }
}
void ordenamientoShell(int arr[], int longitud) {
    int i, j, k, intervalo = longitud / 2; 
    int temp; 
    while (intervalo>0)
    {
        for (int i = intervalo; i <=longitud; i++)
        {
            j = i - intervalo; 
            while (j>=0)
            {
                k = j + intervalo;
                if (arr[j] <= arr[k]) {
                    j = -1; 
                }
                else
                {
                    temp = arr[j];
                    arr[j] = arr[k];
                    arr[k] = temp;
                    j -=intervalo;
                }
            }
        }
        intervalo = intervalo / 2; 
    }
}

// ORDENAMIENTO AVANZADO
void printArray2(vector<int>arreglo) {
    for (int i = 0; i < arreglo.size(); i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void Merge(vector<int>& arreglo, int inicio, int mitad, int final) {
    int i, j, k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int>izquierda(elementosIzq);
    vector<int>derecha(elementosDer);

    for (int i = 0; i < elementosIzq; i++) {
        izquierda[i] = arreglo[inicio + i];
    }
    for (int j = 0; j < elementosDer; j++) {
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < elementosIzq && j < elementosDer) {
        if (izquierda[i] <= derecha[j]) {
            arreglo[k] = izquierda[i];
            i++;
        }
        else {
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (j < elementosDer) {
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while (i < elementosIzq) {
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }

}
void MergeSort(vector<int>& arreglo, int inicio, int fin) {
   
    if (inicio < fin) {
        int mitad = inicio + (fin - inicio) / 2;
        MergeSort(arreglo, inicio, mitad);
        MergeSort(arreglo, mitad + 1, fin);
        Merge(arreglo, inicio, mitad, fin);
    }
}

int partition(vector<int>& arreglo, int start, int end)
{
    int pivot = arreglo[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arreglo[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arreglo[pivotIndex], arreglo[start]);
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arreglo[i] <= pivot) {
            i++;
        }

        while (arreglo[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(arreglo[i++], arreglo[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(vector<int>& arreglo, int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arreglo, start, end);
    quickSort(arreglo, start, p - 1);
    quickSort(arreglo, p + 1, end);
}

int partition2(vector<int>& arreglo, int left, int rigth)
{
    int x = arreglo[rigth], i = left;
    for (int j = left; j <= rigth - 1; j++) {
        if (arreglo[j] <= x) {
            swap(arreglo[i], arreglo[j]);
            i++;
        }
    }
    swap(arreglo[i], arreglo[rigth]);
    return i;
}
int Quickselect(vector<int>& arreglo, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int index = partition2(arreglo, l, r);
        if (index - l == k - 1)
            return arreglo[index];
        if (index - l > k - 1)
            return Quickselect(arreglo, l, index - 1, k);
        return Quickselect(arreglo, index + 1, r,
            k - index + l - 1);
    }
    return INT_MAX;
}

void insertionSort(vector<int>& arreglo, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arreglo[i];
        int j = i - 1;
        while (j >= left && arreglo[j] > temp)
        {
            arreglo[j + 1] = arreglo[j];
            j--;
        }
        arreglo[j + 1] = temp;
    }
}
void timSort(vector<int>& arreglo, int n)
{
    const int RUN = 32;
    for (int i = 0; i < n; i += RUN)
        insertionSort(arreglo, i, min((i + RUN - 1),(n - 1)));
    for (int size = RUN; size < n;
        size = 2 * size)
    {
        for (int left = 0; left < n;
            left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1),
                (n - 1));
            if (mid < right)
                Merge(arreglo, left, mid, right);
        }
    }
}

void heapify(vector<int>& arreglo, int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arreglo[left] > arreglo[largest])
        largest = left;
    if (right < N && arreglo[right] > arreglo[largest])
        largest = right;
    if (largest != i) {
        Swap(&arreglo[i], &arreglo[largest]);
        heapify(arreglo, N, largest);
    }
}
void heapSort(vector<int>& arreglo, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arreglo, N, i);
    for (int i = N - 1; i >= 0; i--) {
        Swap(&arreglo[0], &arreglo[i]);
        heapify(arreglo, i, 0);
    }
}


int main()
{
    srand(time(NULL));

    int arr[10] = { 2,13,4,213,4144,2325,245,26674,8675,4635 };
    int longitud = 10;
    vector<int> prueba1 = { 12,0,6,2,9,34,1 };

    /*algoritmoFisherYates(arr,longitud); (No funciona xd)*/
    /*OrdenamientoIntercambio(arr, longitud); */
    /*Burbuja(arr, longitud);*/ 
    /*OrdenamientoSeleccion(arr, longitud);*/
    /*OrdenaminetoInsercion(arr, longitud);*/
    /*ordenamientoShell(arr, longitud); */
    /*printArray(arr, longitud); */

    /*MergeSort(prueba1, 0, prueba1.size() - 1);
    printArray2(prueba1);
    cout << endl; 
    quickSort(prueba1, 0, prueba1.size() - 1);
    printArray2(prueba1);
    cout << endl;
    Quickselect(prueba1, 0, prueba1.size() - 1, prueba1.size()); 
    printArray2(prueba1);
    cout << endl;
    timSort(prueba1, prueba1.size());
    printArray2(prueba1);
    cout << endl;
    heapSort(prueba1, prueba1.size()); 
    printArray2(prueba1);*/

    _getch(); 
    return 0;
}
