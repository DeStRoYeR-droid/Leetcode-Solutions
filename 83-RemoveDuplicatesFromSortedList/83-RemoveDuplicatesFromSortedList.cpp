// Last updated: 13/07/2026, 22:28:02
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* trav = head;
        while (trav != nullptr){
            while (trav->next != nullptr && trav->val == trav->next->val){
                ListNode* next = trav->next;
                trav->next = next->next;
                delete next;
            }
            trav = trav->next;
        }
        return head;
    }
};