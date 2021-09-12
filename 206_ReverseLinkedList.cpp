#include <gtest/gtest.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return resultHead_;
    }

    ListNode* reverse(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) {
            resultHead_ = head;
            return head;
        }
        ListNode* next = reverse(head->next);
        next->next = head;
        head->next = nullptr;
        return head;
    }

private:
    ListNode* resultHead_ = nullptr;
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* current = head;
        ListNode* prev = nullptr;
        while (!current) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
};

TEST(Test_206, case_01) {
    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);
    Solution s;
    auto ret = s.reverseList(&n1);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}