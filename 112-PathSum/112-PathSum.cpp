// Last updated: 13/07/2026, 22:26:55
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
    bool hasPathSum(TreeNode* root, const int& targetSum, int curr = 0) {
        if (root == nullptr) return false;
        curr += root->val;

        if (root->left == nullptr && root->right == nullptr) return curr == targetSum; 
        return hasPathSum(root->right, targetSum, curr) || hasPathSum(root->left, targetSum, curr);
    }
};