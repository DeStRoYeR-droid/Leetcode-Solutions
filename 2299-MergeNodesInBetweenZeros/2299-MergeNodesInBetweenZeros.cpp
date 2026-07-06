// Last updated: 06/07/2026, 18:58:06
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
        ListNode* result = new ListNode();
        ListNode* header = result;
        ListNode* prev;
        ListNode* trav = head;
        while (trav != nullptr){
            if (trav->val == 0){
                int cur_val = 0;
                trav = trav->next;
                while (trav != nullptr && trav->val != 0){
                    cur_val += trav->val;
                    trav = trav->next;
                }
                result->next = new ListNode(cur_val);
                prev = result;
                result = result->next;
            }
        }
        prev->next = nullptr;
        result = header->next;
        delete header;
        return result;
    }
};