#include <iostream>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    int profit = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main() {
    // Hardcoded example: you can modify this array
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    std::cout << "all Prices: ";
    for (int price : prices) {
        std::cout << price << " ";
    }
    std::cout << "\n";

    int profit = maxProfit(prices);
    std::cout << "total Profit: " << profit << std::endl;

    return 0;
}

