// Last updated: 20/07/2026, 15:43:22
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
    int countDominantNodes(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

    int dfs(TreeNode* node, int& result){
        if (node == nullptr) return 0;

        int l = dfs(node->left, result);
        int r = dfs(node->right, result);

        int maxi = max(node->val, max(l, r));
        if (node->val == maxi) ++result;
        return maxi;
    }
};