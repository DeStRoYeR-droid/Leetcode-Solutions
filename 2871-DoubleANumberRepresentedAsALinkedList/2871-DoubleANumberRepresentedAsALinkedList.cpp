// Last updated: 06/07/2026, 18:54:58
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
    ListNode* doubleIt(ListNode* head) {
        cin.tie(NULL);
        cout.tie(NULL);
        int val = helper(head);
        if (val != 0){
            ListNode* actual = new ListNode(val);
            actual->next = head;
            head = actual;
        }
        return head;
    }
    int helper(ListNode* node){
        int val;
        if (node->next == nullptr) val = node->val << 1;
        else val = (node->val << 1) + helper(node->next);   

        node->val = val % 10;
        return val / 10;
    }
};