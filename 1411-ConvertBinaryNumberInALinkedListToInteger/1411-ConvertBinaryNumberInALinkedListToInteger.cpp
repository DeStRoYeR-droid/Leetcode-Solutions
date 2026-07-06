// Last updated: 06/07/2026, 19:04:30
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