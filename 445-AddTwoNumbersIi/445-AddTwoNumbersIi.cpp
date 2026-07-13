// Last updated: 13/07/2026, 22:19:34
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
    ListNode*reverse(ListNode*head){
        ListNode*prev = nullptr;
        ListNode*temp = head;
        ListNode*front = nullptr;
        while(temp != nullptr){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;

        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode*dummy = new ListNode(-1);
        ListNode*curr = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
        return reverse(dummy->next);
    }
};