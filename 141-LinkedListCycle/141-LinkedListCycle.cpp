// Last updated: 13/07/2026, 22:25:59
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) return false;
        if (head->next == NULL) return false;
        if (head->next->next == NULL) return false;

        ListNode* hare = head;
        ListNode* tortoise = head->next;
        while (hare != NULL && tortoise != NULL){
            if (hare == tortoise) return true;
            if (tortoise->next == NULL) break;
            hare = hare->next;
            tortoise = tortoise->next->next;
        }

        return false;
    }
};