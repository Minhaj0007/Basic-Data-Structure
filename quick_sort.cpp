//quick sort
#include <iostream>
using namespace std;

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to rearrange array (partition)
int partition(int array[], int low, int high)
{

    // select the rightmost element as pivot
    int pivot = array[high];

    // index of smaller element
    int i = low - 1;

    // traverse the array
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // place pivot at correct position
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

// quick sort function
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int data[n];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    cout << "Unsorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;

    // perform quick sort
    quickSort(data, 0, n - 1);

    cout << "Sorted array in ascending order:\n";

    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
    return 0;
}
