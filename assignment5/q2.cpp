#include <iostream>
#include <string>

std::string removeKdigits(std::string num, int k) {
    std::string result;
    
    for (char digit : num) {
        while (!result.empty() && k > 0 && result.back() > digit) {
            result.pop_back();
            --k;
        }
        result.push_back(digit);
    }

    while (k-- > 0 && !result.empty()) {
        result.pop_back();
    }

    size_t start = result.find_first_not_of('0');
    if (start == std::string::npos) return "0";
    return result.substr(start);
}

int main() {
    std::string num = "1432219";
    int k = 3;

    std::string smallest = removeKdigits(num, k);
    std::cout << "number: " << num << std::endl;
    std::cout << "digits to remove: " << k << std::endl;
    std::cout << "smallest possible number: " << smallest << std::endl;

    return 0;
}
