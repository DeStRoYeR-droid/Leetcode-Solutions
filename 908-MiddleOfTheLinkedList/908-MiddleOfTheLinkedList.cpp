// Last updated: 06/07/2026, 19:07:29
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
    ListNode* middleNode(ListNode* head) {
        int length = (head != nullptr);
        ListNode* cur = head;
        while (cur != nullptr){length++; cur = cur->next;}
        
        int ind = 0;
        ListNode* result = head;
        int middle = (length % 2) ? (length >> 1): (length >> 1) - 1;
        while (ind < middle){
            ind++;
            result = result->next;
        }
        return result;
    }
};