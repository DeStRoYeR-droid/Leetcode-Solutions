// Last updated: 13/07/2026, 22:23:52
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
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* next = head;
        ListNode* heading = head;

        while (next != nullptr){
            heading = next->next;
            next->next = prev;
            prev = next;
            next = heading;
        }
        return prev;
    }
};