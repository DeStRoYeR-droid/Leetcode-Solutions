// Last updated: 13/07/2026, 22:17:25
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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long result = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()){
            int n = q.size();
            unsigned long long lMost = ULLONG_MAX, rMost = 0;
            for (int i = 0; i < n; ++i){
                auto [node, level] = q.front(); q.pop();
                lMost = min(lMost, level);
                rMost = max(rMost, level);
                if (node->left) q.push({node->left, 2 * level});
                if (node->right) q.push({node->right, 2 * level + 1});
            }
            result = max(result, rMost - lMost + 1);
        }
        return result;
    }
};