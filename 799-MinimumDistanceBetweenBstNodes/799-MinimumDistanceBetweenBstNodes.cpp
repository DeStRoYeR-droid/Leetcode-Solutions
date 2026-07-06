// Last updated: 06/07/2026, 19:08:32
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
    int minDiffInBST(TreeNode* root) {
        if (root == nullptr) return INT_MAX;
        vector<int> inorder;
        getInorderTraversal(root, inorder);
        
        int result = INT_MAX;
        for (int i = 1; i < inorder.size(); i++)
            result = min(result, inorder[i] - inorder[i-1]);
        
        return result;
    }

    void getInorderTraversal(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;

        getInorderTraversal(root->left, v);
        v.push_back(root->val);
        getInorderTraversal(root->right, v);
    }
};