// Last updated: 06/07/2026, 19:03:48
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
private:
    int maxLength = 0;
public:
    void solve(TreeNode* root, int dir, int length){
        if (!root) return;
        maxLength = max(maxLength, length);
        solve(root->left, 0, dir ? length + 1 : 1);
        solve(root->right, 1, dir ? 1 : length + 1);
    }
    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        solve(root, 1, 0);
        return maxLength;
    }
};