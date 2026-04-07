#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

std::string buildLongestPalindrome(const std::string& s, int& length) {
    std::unordered_map<char, int> count;
    for (char c : s) {
        ++count[c];
    }

    std::string half = "";
    char middle = '\0';
    length = 0;

    for (auto& pair : count) {
        int freq = pair.second;
        length += (freq / 2) * 2;
        half += std::string(freq / 2, pair.first);
        if (freq % 2 == 1 && middle == '\0') {
            middle = pair.first;
            ++length;
        }
    }

    std::string reversed_half = half;
    std::reverse(reversed_half.begin(), reversed_half.end());

    if (middle != '\0') {
        return half + middle + reversed_half;
    } else {
        return half + reversed_half;
    }
}

int main() {
    std::string s = "abccccdd";
    int len = 0;
    std::string palindrome = buildLongestPalindrome(s, len);

    std::cout << "output: " << len << ", the longest palindrome that can be built is \"" << palindrome << "\"." << std::endl;

    return 0;
}

