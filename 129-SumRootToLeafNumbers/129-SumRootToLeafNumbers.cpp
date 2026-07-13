// Last updated: 13/07/2026, 22:26:26
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
    int sumNumbers(TreeNode* root) {
        int result = 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});

        while (!q.empty()){
            auto [node, val] = q.front(); q.pop();

            if (node->left == nullptr && node->right == nullptr){
                result += val;
            }

            if (node->left){
                q.push({node->left, val * 10 + node->left->val});
            }
            if (node->right){
                q.push({node->right, val * 10 + node->right->val});
            }
        }
        return result;
    }
};