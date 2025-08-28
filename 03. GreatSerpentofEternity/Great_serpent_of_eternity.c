#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    int n, x;
    scanf("%d", &n); // number of nodes
    struct ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = x;
        node->next = NULL;
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    struct ListNode* mid = middleNode(head);
    printf("%d\n", mid->val);
    return 0;
}
