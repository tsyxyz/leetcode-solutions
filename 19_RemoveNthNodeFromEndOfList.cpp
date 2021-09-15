#include <gtest/gtest.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; ++i) {
            if (!fast) {
                return nullptr;
            }
            fast = fast->next;
        }
        ListNode* pre = nullptr;
        while (fast) {
            pre = slow;
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* newHead = head;
        if (slow == head) {
            newHead = slow->next;
//            delete slow;
            return newHead;
        }
        if (pre) {
            pre->next = slow->next;
        }
//        delete slow;
        return newHead;
    }
};