#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    
    //count frequency
    for (char task : tasks) {
        freq[task - 'A']++;
    }

    //sort frequencies
    sort(freq.begin(), freq.end(), greater<int>());
    
    //finds max frequency
    int maxFreq = freq[0];
    int countMaxFreq = count(freq.begin(), freq.end(), maxFreq);
    
    //compute min intervals
    int minTime = (maxFreq - 1) * (n + 1) + countMaxFreq;
    
    //returns max time
    return max(minTime, (int)tasks.size());
}

int main() {
    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    cout << "Output 1: " << leastInterval(tasks1, n1) << endl;

    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;
    cout << "Output 2: " << leastInterval(tasks2, n2) << endl;

    vector<char> tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n3 = 3;
    cout << "Output 3: " << leastInterval(tasks3, n3) << endl;

    return 0;
}
