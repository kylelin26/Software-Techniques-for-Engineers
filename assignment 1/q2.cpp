/*
a)
(2,1),(3,1),(8,1),(6,1),(8,6)

b)
The most inversions will be (n...1) has the most inversions. (n*(n+))/2

c)
Insertion sort works by moving elements to their correct position in a sorted array. Each inversion is proportional to a pair that needs to be swapped to sort the array. 
The best case is that it is already sorted, so the number of inversions is 0, and the running time is  O(n). And the worse case is that it is sorted in reverse order, so the number of inversions 
is 2n and the run time is O(n​)^2. The running time of insertion sort is directly proportional to the number of inversions in the array because each inversion requires a comparison and swap.  

d)
*/
#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left, inv_count = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv_count += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    return inv_count;
}

int mergeSortAndCount(vector<int>& arr, int left, int right) {
    int inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, left, mid);
     
        inv_count += mergeSortAndCount(arr, mid + 1, right);

        inv_count += mergeAndCount(arr, left, mid, right);
    }
    return inv_count;
}

int countInversions(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 3, 8, 6, 1};
    cout << "Number of inversions: " << countInversions(arr) << endl;
    return 0;
}
