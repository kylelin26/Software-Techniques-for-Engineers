#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hIndex(vector<int>& citations) {
    
    sort(citations.begin(), citations.end()); //oragnize citation list

    int n = citations.size();
    int h = 0;

    for (int i = 0; i < n; ++i) { //goes from highest to lowest
        int papersCit = n - i; 
        if (citations[i] >= papersCit) {
            return papersCit;
        }
    }
    
    return 0;
}

int main() {

    vector<int> citations = {3, 0, 6, 1, 5, 8};
    
    int result = hIndex(citations); //calculates the h-index

    cout << "The h index is " << result << endl;

    return 0;
}
