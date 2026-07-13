// Last updated: 13/07/2026, 22:23:00
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
    void count(TreeNode* node, int idx, int& result){
        if (node == nullptr) return;
        result = max(result, idx);
        count(node->right, 2 * idx + 1, result);
        count(node->left, 2 * idx, result);
    }

    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int result = 0;
        count(root, 1, result);
        return result;
    }
};