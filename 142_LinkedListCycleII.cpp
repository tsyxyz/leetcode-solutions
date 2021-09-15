#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (true) {
            if (!fast || !fast->next) {
                return nullptr;
            }

            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};