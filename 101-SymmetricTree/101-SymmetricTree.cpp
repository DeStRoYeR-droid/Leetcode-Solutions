// Last updated: 13/07/2026, 22:27:35
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
    bool isSymmetric(TreeNode* root) {
        return checkEqual(root->left, root->right);
    }
    bool checkEqual(TreeNode* head1, TreeNode* head2){
        if (head1 == nullptr && head2) return false;
        if (head1 && head2 == nullptr) return false;

        if (head1 == nullptr && head2 == nullptr) return true;
        if (head1->val != head2->val) return false;
        if (!(checkEqual(head1->left, head2->right))) return false;
        if (!(checkEqual(head1->right, head2->left))) return false;
        return true;
    }
};