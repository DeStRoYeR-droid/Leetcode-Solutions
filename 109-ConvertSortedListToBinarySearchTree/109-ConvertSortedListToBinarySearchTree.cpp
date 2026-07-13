// Last updated: 13/07/2026, 22:27:00
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        return helper(head, nullptr);
    }

    TreeNode* helper(ListNode* head, ListNode* tail) {
        if (head == tail)
            return nullptr;
        ListNode* middle = find_middle(head, tail);
        TreeNode* root = new TreeNode(middle->val);
        root->left = helper(head, middle);
        root->right = helper(middle->next, tail);
        return root;
    }

    inline ListNode* find_middle(ListNode* head, ListNode* tail) {
        if (!head)
            return nullptr;
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};