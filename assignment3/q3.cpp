#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool isSubsequence(const string& a, const string& b) { //checks if a is subsequence to b
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            i++;
        }
        j++;
    }
    return i == a.size();
}

int findLUSlength(vector<string>& strs) { //finds uncommon subsecquence
    int maxLength = -1;
    
   
    for (int i = 0; i < strs.size(); ++i) { //checks string list
        bool isUncommon = true;

        for (int j = 0; j < strs.size(); ++j) { //compares i with other string
            if (i != j && isSubsequence(strs[i], strs[j])) {
                isUncommon = false;
                break;
            }
        }

        if (isUncommon) { //uncommon and updates max length
            maxLength = max(maxLength, (int)strs[i].size());
        }
    }

    return maxLength;
}

int main() {
    vector<string> strs = {"abc", "ab", "abc", "a"};

    int result = findLUSlength(strs); //compute subsequence

    cout << "Longest Uncommon Subsequence Length: " << result << endl;

    return 0;
}
