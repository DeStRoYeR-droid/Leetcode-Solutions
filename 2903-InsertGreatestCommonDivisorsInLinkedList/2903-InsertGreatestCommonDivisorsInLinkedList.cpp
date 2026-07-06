// Last updated: 06/07/2026, 18:54:49
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
int gcd_helper(int a, int b){
    if (a % b == 0) return b;
    return gcd_helper(b, a % b);
}

int gcd(int a, int b){
    if (a < b) return gcd_helper(b,a);
    return gcd_helper(a,b);
}



class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* result = head;
        ListNode* trav = head;
        ListNode* next = head->next;
        while (next != nullptr){
            int number = gcd(trav->val, next->val);
            trav->next = new ListNode(number);
            trav->next->next = next;

            trav = next;
            next = trav->next;
        }
        return result;
    }
};

