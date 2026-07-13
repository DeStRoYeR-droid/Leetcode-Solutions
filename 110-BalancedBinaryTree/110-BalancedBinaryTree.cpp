// Last updated: 13/07/2026, 22:26:58
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int hL = height(root->left, 0);
        int hR = height(root->right, 0);
        if (abs(hL - hR) > 1) return false;
        if (!(isBalanced(root->left))) return false;
        if (!(isBalanced(root->right))) return false;
        return true;
    }
    int height(TreeNode* root, int depth){
        if (root == nullptr) return depth;
        return max(height(root->left, depth + 1), height(root->right, depth + 1));
    }
};