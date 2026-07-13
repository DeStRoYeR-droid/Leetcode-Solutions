// Last updated: 13/07/2026, 22:17:31
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
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        vector<int> result;
        inorder(root, result);

        int l = 0, r = result.size() - 1;
        while (l < r){
            if (result[l] + result[r] == k) return true;
            else if (result[l] + result[r] > k) --r;
            else ++l;
        }
        return false;
    }

    void inorder(TreeNode* root, vector<int>& result){
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};