// Last updated: 13/07/2026, 22:30:47
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* header = result;
        int res;

        bool carry = false;
        while (l1 != NULL && l2!= NULL){
            res = l1->val + l2->val + carry;
            carry = res >= 10;
            res = res % 10;
            result->next = new ListNode(res);
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != NULL){
            res = l1->val + carry;
            carry = res >= 10;
            res = res % 10;
            result->next = new ListNode(res);
            result = result->next;
            l1 = l1->next;
        }

        while (l2 != NULL){
            res = l2->val + carry;
            carry = res >= 10;
            res = res %10;
            result->next = new ListNode(res);
            result = result->next;
            l2 = l2->next;
        }

        if (carry){
            result->next = new ListNode(carry);
            result = result->next;
        }

        result = header->next;
        delete header;
        return result;
    }
};