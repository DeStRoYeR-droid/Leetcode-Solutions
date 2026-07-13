// Last updated: 13/07/2026, 22:22:30
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int left = min(p->val , q->val);
        int right = max(p->val , q->val);
        
        while (left > root->val || right < root->val){
            if (root->val > right) root = root->left;
            if (root->val < left) root = root->right;
        }

        return new TreeNode(root->val);
    }
};