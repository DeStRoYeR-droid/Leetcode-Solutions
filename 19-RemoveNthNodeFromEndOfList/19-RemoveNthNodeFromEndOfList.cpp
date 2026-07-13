// Last updated: 13/07/2026, 22:30:09
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* trav = head;
        ListNode* lagg = head;
        int index = 0;
        while (index < n && trav != nullptr){
            trav = trav->next;
            ++index;
        }
        
        if (trav == nullptr && index != n) return nullptr;
        else if (trav == nullptr && index == n) return head->next;

        while (trav->next != nullptr){
            trav = trav->next;
            lagg = lagg->next;
        }
        lagg->next = lagg->next->next;
        return head;
    }
};