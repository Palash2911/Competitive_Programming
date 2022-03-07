#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2]; //temp arrays
    cout<<n1<<" "<<n2<<endl;
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}
void mergesort(int arr[], int l, int r)
{
    // l==r means only one elment
    if (l < r)
    {
        int mid = (l + r) / 2;
        // cout<<l<<" "<<mid<<" f"<<endl;
        mergesort(arr, l, mid);
        // cout<<mid+1<<" "<<r<<" s"<<endl;
        mergesort(arr, mid + 1, r);
        // cout<<l<<" "<<mid<<" "<<r<<" t"<<endl;
        merge(arr, l, mid, r);
    }
}
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    // cout<<pivot<<endl;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return (i + 1);
}
void quicks(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        cout<<pi<<endl;
        quicks(arr, l, pi - 1);
        quicks(arr, pi + 1, r);
    }
}
void counts(int arr[], int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void swap1(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void dnf(int arr[], int n)
{
    int low=0;
    int mid=0;
    int high=n-1;
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap1(arr,low,mid);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap1(arr,mid,high);
            high--;
        }
    }
}

void swap2(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void wave(int arr[], int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i]>arr[i-1])
        {
            swap2(arr,i,i-1);
        }
        if(arr[i]>arr[i+1] && i<=n-2)
        {
            swap2(arr,i,i+1);
        }
    }
}

void countinve(int arr[], int n)
{
    int inv=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j] && i<j)
            {
                inv++;
            }
        }
    }
    cout<<inv<<endl;
}
int main()
{
    // 1. MERGE SORT   - Uses divide and conquer algo. - merge and mergesort func.
    // int arr[]={4,2,6,3,5,1,8,7};
    // mergesort(arr,0,7);

    //   for(int i=0;i<8;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    // 2. QUICK SORT -  uses divide and conquer algo. - partition, quicks, swap func.
    int arr[]={9,7,5,11,12,2};
    quicks(arr,0,5);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // 3.COUNT SORT- counts
    // int arr[]={4,2,5,1,3};
    // counts(arr, 5);

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    // 4.DNF sort - dutch national flag algorithm- dnf and swap1
    // int arr[]={1,0,2,1,0,1,2,1,2};
    // dnf(arr, 9);
    // for(int i=0;i<9;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }

    // 5.wave sort. - make array in wave form - important - wave and swap 
    //   int arr[]={1,3,4,7,5,6,2};
    // wave(arr, 7);

    // for (int i = 0; i < 7; i++)
    // {
    //     cout << arr[i] << " ";
    //     // here the array is in wave form not normally.
    // }

    // 6. count inversion- inversion is if a[i]>a[j] and i<j - this is not a sorting techinque 
    //    int arr[]={3,5,6,9,1,2,7,8};
    // countinve(arr, 8);

    return 0;
}

