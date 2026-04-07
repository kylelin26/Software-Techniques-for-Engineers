#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class foodTable {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
       
        map<int, unordered_map<string, int>> tableNumbersAndFoodItemsCount;  // map to store table number and corresponding food item counts
        
        set<string> foodItems; // set to store unique food items in alphabetical order

        for (int i = 0; i < orders.size(); i++) {
            string foodItem = orders[i][2];
            int tableNumber = stoi(orders[i][1]);
            
            foodItems.insert(foodItem); // add food item to the set
            
            tableNumbersAndFoodItemsCount[tableNumber][foodItem]++; // increment count for the food item at the table
        }

        vector<string> tableHeader{"Table"};
        for (const auto& food : foodItems) {
            tableHeader.push_back(food);
        }

        vector<vector<string>> ans{tableHeader};
        
        for (const auto& table : tableNumbersAndFoodItemsCount) { // process table data and fill results
            int n = foodItems.size() + 1;
            vector<string> temp(n, "0");

            temp[0] = to_string(table.first); // set table number in the first column

            for (const auto& item : table.second) { // fill in food counts for the table
                int pos = find(tableHeader.begin(), tableHeader.end(), item.first) - tableHeader.begin();
                temp[pos] = to_string(item.second);
            }
            
            ans.push_back(temp); // add table data to the result
        }

        return ans;
    }
};

int main() {
   
    vector<vector<string>> orders{
        {"David", "3", "Ceviche"},
        {"Corina", "10", "Beef Burrito"},
        {"David", "3", "Fried Chicken"},
        {"Carla", "5", "Water"},
        {"Carla", "5", "Ceviche"},
        {"Rous", "3", "Ceviche"}
    };

    foodTable solution;

    vector<vector<string>> result = solution.displayTable(orders);
 
    for (const auto& row : result) {
        for (const auto& item : row) {
            cout << item << " ";
        }
        cout << endl;
    }

    return 0;
}
