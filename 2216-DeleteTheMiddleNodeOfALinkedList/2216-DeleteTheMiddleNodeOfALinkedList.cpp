// Last updated: 06/07/2026, 18:58:47
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next == nullptr) return nullptr;
        ListNode* prev;
        ListNode* dbl = head;
        ListNode* cur = head;
        while (dbl != nullptr && dbl->next != nullptr){
            prev = cur;
            cur = cur->next;
            dbl = dbl->next->next;
        }
        prev->next = cur->next;
        delete cur;
        return head;
    }
};