// Last updated: 06/07/2026, 19:06:14
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
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        queue<pair<TreeNode*, int>> pq;
        pq.push({root, root->val});

        while (!pq.empty()){
            auto [node, val] = pq.front(); pq.pop();

            if (node->left == nullptr && node->right == nullptr){
                result += val;
            }
            if (node->left){
                pq.push({node->left, (val << 1) | node->left->val});
            }
            if (node->right){
                pq.push({node->right, (val << 1) | node->right->val});
            }
        }
        return result;
    }
};