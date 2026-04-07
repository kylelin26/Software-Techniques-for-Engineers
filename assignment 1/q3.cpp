#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> relativeSort(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq; //stores frequency of elements in arrary 1
    vector<int> remaining;        //stores elements not in array 2

    
    for (int num : arr1)
        freq[num]++; //count frequencies of array 1 elements

    vector<int> result; 

    
    for (int num : arr2) {
        while (freq[num] > 0) {
            result.push_back(num);
            freq[num]--;
        }
    } //add elements of array 2 in the correct order

    
    for (auto& pair : freq) {
        while (pair.second > 0) {
            remaining.push_back(pair.first);
            pair.second--;
        }
    }

    sort(remaining.begin(), remaining.end()); //sorts remaining elements in ascending orde

    result.insert(result.end(), remaining.begin(), remaining.end()); //appends sorted remaining elements to result
    return result;
}

int main() {
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    vector<int> sortedArr = relativeSort(arr1, arr2);

    cout << "Output: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
