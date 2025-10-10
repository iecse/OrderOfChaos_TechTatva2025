#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "../testlib.h"
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

// Linked-list based solve function
int solve(const vector<int>& serpent) {
    ListNode *head = nullptr, *tail = nullptr;

    // build linked list
    for (int x : serpent) {
        ListNode* node = new ListNode(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // find middle node
    ListNode* mid = middleNode(head);
    int ans = mid->val;

    // cleanup
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return ans;
}

void writeTest(int z) {
    string num = (z > 9) ? to_string(z) : "0" + to_string(z);
    fstream test;
    fstream answer;
    test.open("Input" + num + ".txt", ios::out);
    answer.open("Output" + num + ".txt", ios::out);

    // total testcases
    int t = rnd.next(1, 100); // keep small for demonstration
    test << t << "\n";

    int totalN = 0;
    for (int tc = 0; tc < t; tc++) {
        int remaining = 200000 - totalN;
        int maxN = min(remaining, 1000); // cap n per testcase for generator
        int n = rnd.next(1, maxN);

        totalN += n;
        test << n << "\n";

        vector<int> serpent(n);
        for (int i = 0; i < n; i++) {
            serpent[i] = rnd.next(0, 10000);
            test << serpent[i] << (i == n - 1 ? "\n" : " ");
        }

        int ans = solve(serpent);
        answer << ans << "\n";
    }

    test.close();
    answer.close();
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    for (int no = 0; no < 3; no++) {
        writeTest(no);
    }
    return 0;
}
