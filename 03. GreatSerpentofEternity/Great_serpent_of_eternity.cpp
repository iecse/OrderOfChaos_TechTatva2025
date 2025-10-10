#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void solve() {
    int n, x;
    cin >> n; // number of nodes

    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ListNode* node = new ListNode(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    ListNode* mid = middleNode(head);
    cout << mid->val << "\n";

    // cleanup linked list
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; // number of testcases
    while (t--) {
        solve();
    }

    return 0;
}
