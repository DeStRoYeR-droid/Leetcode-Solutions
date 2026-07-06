// Last updated: 06/07/2026, 19:06:41
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
    bool isUnivalTree(TreeNode* root, int val = -1) {
        if (root == nullptr) return true;
        val = (val == -1) ? root->val : val;
        if (root->val != val) return false;
        if (!isUnivalTree(root->left, val)) return false;
        if (!isUnivalTree(root->right, val)) return false;
        return true;
    }
};