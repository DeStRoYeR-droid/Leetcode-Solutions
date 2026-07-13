// Last updated: 13/07/2026, 22:27:57
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;

        ListNode dummy(0); 
        dummy.next = head;
        ListNode* lastSmall = &dummy; 
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                if (lastSmall->next == curr) {
                    lastSmall = curr;
                    prev = curr;
                    curr = curr->next;
                } else {
                    prev->next = curr->next;
                    curr->next = lastSmall->next;
                    lastSmall->next = curr;
                    lastSmall = curr;
                    curr = prev->next;
                }
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};