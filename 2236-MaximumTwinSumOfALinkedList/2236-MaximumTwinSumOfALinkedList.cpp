// Last updated: 06/07/2026, 18:58:37
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
    int pairSum(ListNode* head) {
        ListNode* copy = nullptr;
        ListNode* trav = head;
        ListNode* trav2 = head;
        int size = 0;
        int result = 0;
        int index = 0;

        while (trav != nullptr){
            ListNode* cur = new ListNode(trav->val);
            cur->next = copy;
            copy = cur;
            trav = trav->next;
            ++size;
        }
        trav = copy;
        
        while (index <= size / 2){
            result = max(result, trav->val + trav2->val);
            trav = trav->next;
            trav2 = trav2->next;
            ++index;
        }
        return result;
    }
};