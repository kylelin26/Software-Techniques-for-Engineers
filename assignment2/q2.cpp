#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int strongPasswordChecker(string password) {
    int n = password.size();
    bool hasLower = false, hasUpper = false, hasDigit = false;

    vector<int> repeatLengths; 
    int changes = 0, missingTypes = 3;

    //checks requirments
    for (int i = 0; i < n;) {
        if (islower(password[i])) hasLower = true;
        if (isupper(password[i])) hasUpper = true;
        if (isdigit(password[i])) hasDigit = true;

        int j = i;
        while (j < n && password[j] == password[i]) j++;

        int len = j - i;
        if (len >= 3) repeatLengths.push_back(len);

        i = j;
    }

    //counts and adds whats missing
    missingTypes -= hasLower + hasUpper + hasDigit; 

    if (n < 6) {
        
        return max(6 - n, missingTypes); //if password is too short
    } else if (n <= 20) {
        
        int replaceCount = 0;
        for (int len : repeatLengths) {
            replaceCount += len / 3;
        } // right length but repeating
        return max(replaceCount, missingTypes);
    } else {
       
        int removeCount = n - 20, replaceCount = 0; //too long 

        
        for (int i = 0; i < repeatLengths.size(); i++) {
            if (repeatLengths[i] % 3 == 0 && removeCount > 0) {
                repeatLengths[i] -= 1;
                removeCount--;
            } //breaks up groups
        }
        for (int i = 0; i < repeatLengths.size(); i++) {
            if (repeatLengths[i] % 3 == 1 && removeCount > 0) {
                repeatLengths[i] -= 2;
                removeCount -= 2;
            }
        }
        for (int i = 0; i < repeatLengths.size(); i++) {
            while (repeatLengths[i] >= 3 && removeCount > 0) {
                repeatLengths[i] -= 3;
                removeCount -= 3;
            }
        }

        for (int len : repeatLengths) {
            replaceCount += len / 3;
        }

        return (n - 20) + max(replaceCount, missingTypes);
    }
}


int main() {
    string password1 = "a";
    cout << "Changes needed for " << password1 << ": " << strongPasswordChecker(password1) << endl;

    string password2 = "aA1";
    cout << "Changes needed for " << password2 << ": " << strongPasswordChecker(password2) << endl;

    string password3 = "1337C0d3";
    cout << "Changes needed for " << password3 << ": " << strongPasswordChecker(password3) << endl;

    string password4 = "Testing123";
    cout << "Changes needed for " << password4 << ": " << strongPasswordChecker(password4) << endl;

    return 0;
}
