#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    const int n = 100;
    int arr[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    int key = 100;

    auto start = high_resolution_clock::now();
    int index = linearSearch(arr, n, key);
    auto stop = high_resolution_clock::now();

    cout << "Linear Search" << endl;
    cout << "Element found at index " << index << endl;
    cout << "Time Taken : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    start = high_resolution_clock::now();
    index = binarySearch(arr, n, key);
    stop = high_resolution_clock::now();

    cout << endl;
    cout << "Binary Search" << endl;
    cout << "Element found at index " << index << endl;
    cout << "Time Taken : "
         << duration_cast<microseconds>(stop - start).count()
         << " microseconds" << endl;

    return 0;
}