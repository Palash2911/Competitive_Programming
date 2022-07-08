#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] > a[j])
        {
            j = j + 1;
        }
        if (temp > a[j])
        {
            break;
        }
        else if (temp <= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}

void build_maxH(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxHeapify(a, i, n);
    }
}
void max_heap(int a[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        maxHeapify(a, 1, i - 1);
    }
}

void min_heapify(int a[], int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
        {
            j = j + 1;
        }
        if (temp < a[j])
        {
            break;
        }
        else if (temp >= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = temp;
}
void build_minH(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        min_heapify(a, i, n);
    }
}
void min_heap(int ar[], int n)
{
    int i, temp;
    for (i = n; i >= 2; i--)
    {
        temp = ar[i];
        ar[i] = ar[1];
        ar[1] = temp;
        min_heapify(ar, 1, i - 1);
    }
}

void print(int arr[], int n)
{
    cout << endl<< "Sorted Elements :  ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, i, ch;
    cout << endl<< "Enter The Number of Elements :  ";
    cin >> n;
    int arr[n];
    cout << endl<< "Enter Elements :  ";
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    do
    {
        cout << endl<< endl<< "1. Heapsort Using MinHeap " << endl;
        cout << "2. Heapsort Using MaxHeap " << endl;
        cout << "3. Exit. " << endl;
        cout << "Enter Your Choice :  ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            build_minH(arr, n);
            min_heap(arr, n);
            print(arr, n);
            break;
        case 2:
            build_maxH(arr, n);
            max_heap(arr, n);
            print(arr, n);
            break;
        case 3:
            cout << endl
                 << "Thank You :))" << endl;
            break;
        default:
            cout << endl
                 << "Invalid Choice !!" << endl;
            break;
        }
    } while (ch != 3);

    return 0;
}