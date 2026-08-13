#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

void heapify(vector<int>& a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a)
{
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto start = high_resolution_clock::now();

    heapSort(a);

    auto end = high_resolution_clock::now();

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    auto time = duration_cast<microseconds>(end - start);

    cout << "\nExecution time: " << time.count() << " microseconds";

    return 0;
}
