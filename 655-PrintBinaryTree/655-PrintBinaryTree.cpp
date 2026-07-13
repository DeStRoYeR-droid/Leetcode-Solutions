// Last updated: 13/07/2026, 22:17:30
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
    int maxDepth(TreeNode* root){
        if (root == nullptr) return 0;
        else return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    void fillTree(TreeNode* root, vector<vector<string>>& result, int r, int c, int h){
        if (root == nullptr) return;
        result[r][c] = to_string(root->val);
        fillTree(root->left, result, r + 1, c - pow(2, h - r - 2), h);
        fillTree(root->right, result, r + 1, c + pow(2, h - r - 2), h);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int depth = maxDepth(root);
        int n = pow(2, depth) - 1;
        vector<vector<string>> result(depth, vector<string>(n, ""));
        fillTree(root, result, 0, (n - 1)/ 2, depth);
        return result;
    }
};