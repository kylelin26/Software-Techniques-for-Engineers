#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct ListNode { // define singly-linked list
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class LIST {
public:
    ListNode* sortList(ListNode* head) { // extract the values into a vector
        if (head == NULL || head->next == NULL)
            return head;

        vector<int> values;
        ListNode* current = head;
        while (current != NULL) {
            values.push_back(current->val);
            current = current->next;
        }
        
        sort(values.begin(), values.end()); // sort the values

        
        ListNode* dummy = new ListNode(0); // create a new sorted linked list
        ListNode* sortedCurrent = dummy;

        for (int val : values) {
            sortedCurrent->next = new ListNode(val);
            sortedCurrent = sortedCurrent->next;
        }

        
        return dummy->next; // return the new head
    }
};


ListNode* createLinkedList(vector<int>& values) { // create a linked list from a vector
    if (values.empty())
        return NULL;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}


void printLinkedList(ListNode* head) { // print the linked list
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val;
        if (current->next != NULL)
            cout << ", ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    vector<int> values1 = {4, 2, 1, 3};
    ListNode* head1 = createLinkedList(values1);
    LIST solution;
    ListNode* sortedHead1 = solution.sortList(head1);
    cout << "Sorted list 1: ";
    printLinkedList(sortedHead1);

    vector<int> values2 = {-1, 5, 3, 4, 0};
    ListNode* head2 = createLinkedList(values2);
    ListNode* sortedHead2 = solution.sortList(head2);
    cout << "Sorted list 2: ";
    printLinkedList(sortedHead2);

    vector<int> values3 = {};
    ListNode* head3 = createLinkedList(values3);
    ListNode* sortedHead3 = solution.sortList(head3);
    cout << "Sorted list 3: ";
    printLinkedList(sortedHead3);

    return 0;
}
