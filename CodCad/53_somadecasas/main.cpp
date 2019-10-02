#include <iostream>
#include <algorithm>

using namespace std;

int busca_binaria(int arr[], int low, int high, int value)
{
    int pivot;
    while(low <= high)
    {
        pivot = (low+high)/2;

        if(value == arr[pivot]) return pivot;
        if(value < arr[pivot]) high = pivot-1;
        else low = pivot + 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;

    for(int i = 0; i < n; i++){
        if(arr[i] < k)
        {
            int index = busca_binaria(arr, 0, n-1, k-arr[i]);
            if(index != -1)
            {
                cout << arr[i] << " " << arr[index] << endl;
                break;
            }
        }
    }
    return 0;
}
