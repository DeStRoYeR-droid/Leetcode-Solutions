// Last updated: 06/07/2026, 19:07:35
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1 , nums2;
        leaves(root1 , nums1);
        leaves(root2 , nums2);
        return (nums1 == nums2);
    }
    void leaves(TreeNode* root, vector<int>& stack){
        if (root == nullptr) return;

        if (root->left == nullptr && root->right == nullptr){
            stack.push_back(root->val);
            return;
        }
        else{
            if (root->left) leaves(root->left , stack);
            if (root->right) leaves(root->right, stack);
            return;
        }
        
    }
};