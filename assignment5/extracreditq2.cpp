#include <iostream>
#include <vector>

void findIncreasingTriplets(const std::vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] < nums[j] && nums[j] < nums[k]) {
                    std::cout << "(" << i << ", " << j << ", " << k << ") => "
                              << "(" << nums[i] << " < " << nums[j] << " < " << nums[k] << ")\n";
                }
            }
        }
    }
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    findIncreasingTriplets(nums);
    return 0;
}
