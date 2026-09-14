// Last updated: 14/09/2026, 09:25:44
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
    int getDecimalValue(ListNode* head) {
        int result = 0;
        ListNode* ptr = head;
        while (ptr != nullptr){
            result <<= 1;
            result += ptr->val;
            ptr = ptr->next;
        }
        return result;
    }
};