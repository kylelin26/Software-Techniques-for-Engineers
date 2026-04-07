#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {  // goes through array
        for (int j = i + 1; j < n && j <= i + indexDiff; ++j) { // compares array with index
            if (abs(nums[i] - nums[j]) <= valueDiff) {
                return true; 
            }
        }
    }
    return false;
}

int main() {
    
    vector<int> nums = {1, 5, 9, 13};
    int indexDiff = 2;  
    int valueDiff = 3;  

    bool result = containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff); //stores result

    cout << (result ? "true" : "false") << endl; //prints result

    return 0;
}
