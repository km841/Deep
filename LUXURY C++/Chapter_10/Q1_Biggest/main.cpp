#include "pch.h"

template <typename T>
T biggest(T* arr, int n)
{
    T big = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (big < arr[i]) big = arr[i];
    }

    return big;
}

int main()
{
    int x[] = { 1, 10, 100, 5, 4 };
    cout << biggest(x, 5) << endl;
}
