#include <iostream>
using namespace std;

void sels(int p[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j] < p[i])
            {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }
    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    return;
}
void bubbs(int l[], int n)
{
    int temp, counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (l[i] > l[i + 1])
            {
                temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
            }
        }
        counter++;
    }

    cout << "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << l[i] << " ";
    }
    return;
}
void inses(int ar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cur = ar[i];
        int j = i - 1;
        while (ar[j] > cur && j >= 0)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = cur;
    }
    cout << endl<< "Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return;
}
int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;
    int a[n];
    cout << "Enter array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ch;
    cout << "1.Sort using Selection sort." << endl;
    cout << "2.Sort using Bubble sort." << endl;
    cout << "3.Sort using Insertion sort." << endl;
    cout << endl
         << "Enter your choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        sels(a, n);
        break;
    case 2:
        bubbs(a, n);
        break;
    case 3:
        inses(a, n);
        break;
    default:
        cout << "Wrong choice !!" << endl;
        break;
    }
    return 0;
}