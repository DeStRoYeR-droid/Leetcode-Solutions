// Last updated: 06/07/2026, 19:03:54
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

static const int MOD = 1e9 + 7;
class Solution {
public:
    long long dfs(TreeNode* root){
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        return (left + root->val + right) % MOD;
    }
    
    long long helper(TreeNode* root, long long& result, const long long& total){
        if (root == nullptr) return 0LL;
        
        long long left = helper(root->left, result, total);
        long long right = helper(root->right, result, total);
        long long curr = left + root->val + right;

        result = max(result, (total - curr) * curr);
        return curr;
    }

    int maxProduct(TreeNode* root) {
        long long total = 0LL, result = 0LL;
        total = dfs(root);
        helper(root, result, total);
        return result % MOD;
    }
};