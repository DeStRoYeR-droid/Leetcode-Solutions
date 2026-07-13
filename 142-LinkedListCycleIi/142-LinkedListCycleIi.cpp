// Last updated: 13/07/2026, 22:25:57
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return nullptr;
        if (head->next == NULL) return nullptr;
        if (head->next->next == NULL) return nullptr;

        ListNode* hare = head;
        ListNode* tortoise = head;
        bool hasCycle = false;
        while (tortoise && tortoise->next){
            hare = hare->next;
            tortoise = tortoise->next->next;
            
            if (hare == tortoise){
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return nullptr;

        hare = head;
        while (hare != tortoise){
            hare = hare->next;
            tortoise = tortoise->next;
        }
        return hare;
    }
};