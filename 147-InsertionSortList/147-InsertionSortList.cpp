// Last updated: 13/07/2026, 22:25:49
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *current = head->next;
        ListNode *subCurrent = head;

        while(current != NULL){
            subCurrent = head;
            while(subCurrent != current){
                if(subCurrent->val >= current->val){
                    swap(subCurrent->val,current->val);
                }
                subCurrent = subCurrent->next;
            }
            current = current->next;
        }
        return head;
    }
};