// Last updated: 13/07/2026, 22:28:49
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;

        int length = 1;
        ListNode* trav = head;
        while (trav->next){
            ++length;
            trav = trav->next;
        }

        int position = k % length;
        if (position == 0) return head;

        ListNode* curr = head;
        for (int i = 0; i < length - position-1; ++i){
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        trav->next = head;

        return newHead;
    }
};