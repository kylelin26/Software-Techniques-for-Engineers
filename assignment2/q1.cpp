#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//min heap structure
struct Node {
    int value, row, col;
    
    bool operator>(const Node& other) const {
        return value > other.value;
    }
};

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    //store elements in order
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;

    //puts first element in each row
    for (int i = 0; i < n; i++) {
        minHeap.push({matrix[i][0], i, 0});
    }

    //extracts k-1 elements
    for (int i = 0; i < k - 1; i++) {
        Node node = minHeap.top();
        minHeap.pop();

        int row = node.row, col = node.col;
        
        //pushes next element
        if (col + 1 < matrix[row].size()) {
            minHeap.push({matrix[row][col + 1], row, col + 1});
        }
    }

    return minHeap.top().value;
}


int main() {
    
    vector<vector<int>> matrix1 = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    vector<vector<int>> matrix2 = {{-5}};
    int k1 = 8;
    int k2 = 1;

    cout << kthSmallest(matrix1, k1) << " is the " <<  k1 << "th smallest number in the array."  << endl;
    cout << kthSmallest(matrix2, k2) << " is the " << k2 << "th smallest number in the array."  << endl;

    return 0;
}
