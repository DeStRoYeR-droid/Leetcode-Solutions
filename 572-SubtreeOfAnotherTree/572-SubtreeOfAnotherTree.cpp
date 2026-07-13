// Last updated: 13/07/2026, 22:18:18
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
    bool isSame(TreeNode* main, TreeNode* compare){
        if (main == nullptr) {
            if (compare == nullptr) return true;
            else return false;
        }
        if (compare == nullptr) {
            if (main != nullptr) return false;
        }

        if (main->val != compare->val) return false;

        return isSame(main->left, compare->left) && isSame(main->right, compare->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr ^ subRoot == nullptr) return false;
        if (isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        return false;
    }
};