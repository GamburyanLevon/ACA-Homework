#include <iostream>

void merge(int arr[], int left, int mid, int right) 
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* Larr = new int[n1];
    int* Rarr = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        Larr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        Rarr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (Larr[i] <= Rarr[j]) 
        {
            arr[k] = Larr[i];
            i++;
        } 
        else 
        {
            arr[k] = Rarr[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = Larr[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = Rarr[j];
        j++;
        k++;
    }

    delete[] Larr;
    delete[] Rarr;
}

void mergeSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int m = left + (right - left) / 2;
        mergeSort(arr, left, m);
        mergeSort(arr, m + 1, right);
        merge(arr, left, m, right);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printArray(arr, n);
    return 0;
}
