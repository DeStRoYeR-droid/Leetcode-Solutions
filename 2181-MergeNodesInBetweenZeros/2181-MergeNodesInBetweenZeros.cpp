// Last updated: 07/09/2026, 22:48:46
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* result = head;
        ListNode* prev = nullptr;
        ListNode* trav = head->next;
        int total = 0;
        while (trav != nullptr){
            if (trav->val == 0){
                result->val = total;
                prev = result;
                total = 0;
                result = result->next;
            }
            else{
                total += trav->val;
            }
            trav = trav->next;
        }
        prev->next = nullptr;
        return head;
    }
};