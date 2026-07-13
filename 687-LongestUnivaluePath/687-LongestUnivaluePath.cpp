// Last updated: 13/07/2026, 22:17:09
class Solution {
private:
    int result = 0;
    int dfs(TreeNode* root) {
        int left = root->left ? dfs(root->left) : 0;
        int right = root->right ? dfs(root->right) : 0;
        int l = (root->left && root->left->val == root->val) ? left + 1 : 0;
        int r = (root->right && root->right->val == root->val) ? right + 1 : 0;
        result = max(result, l + r);
        return max(l, r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return result;
    }
};