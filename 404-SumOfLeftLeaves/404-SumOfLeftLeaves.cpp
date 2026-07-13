// Last updated: 13/07/2026, 22:20:08
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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        sumLeaves(root, result, 0);
        return result;
    }

    void sumLeaves(TreeNode* root, int& curr, bool isLeft){
        if (root == nullptr) return;
        if (isLeft && (root->left == nullptr && root->right == nullptr)) curr += root->val;
        sumLeaves(root->left, curr, 1);
        sumLeaves(root->right, curr, 0);
    }
};