#include <iostream>
#include <vector>
#include <numeric>

// Definition for a doubly-linked list node.
struct DoublyListNode {
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// Function to solve a single test case
void solve() {
    int n;
    long long k; // k can be large, so use long long
    std::cin >> n >> k;

    std::vector<int> runes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> runes[i];
    }

    // Handle edge case of an empty list of runes.
    if (n == 0) {
        std::cout << "\n";
        return;
    }

    // --- Build the Doubly Linked List from input ---
    DoublyListNode* head = new DoublyListNode(runes[0]);
    DoublyListNode* current = head;
    for (int i = 1; i < n; ++i) {
        DoublyListNode* new_node = new DoublyListNode(runes[i]);
        current->next = new_node;
        new_node->prev = current;
        current = new_node;
    }
    // 'current' is now the tail of the list.

    // --- Rotation Logic ---
    // If n=1 or k=0 (or a multiple of n), no rotation is needed.
    long long effective_k = k % n;
    if (effective_k != 0) {
        // 1. Make the list circular
        DoublyListNode* tail = current;
        tail->next = head;
        head->prev = tail;

        // 2. Find the new tail of the rotated list.
        // It's the node at position (n - k - 1) from the start.
        DoublyListNode* new_tail = head;
        for (int i = 0; i < n - effective_k - 1; ++i) {
            new_tail = new_tail->next;
        }

        // 3. The new head is the node immediately after the new tail.
        DoublyListNode* new_head = new_tail->next;

        // 4. Break the circular connection.
        new_tail->next = nullptr;
        new_head->prev = nullptr;

        // 5. Update the head pointer to the new head.
        head = new_head;
    }

    // --- Print and Clean Up ---
    current = head;
    while (current != nullptr) {
        std::cout << current->val << (current->next ? " " : "");
        DoublyListNode* temp = current;
        current = current->next;
        delete temp; // Free the allocated memory for the node
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
