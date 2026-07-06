// Last updated: 06/07/2026, 19:06:31
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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> xNode = findNode(nullptr, root, 0, x);
        pair<TreeNode*, int> yNode = findNode(nullptr, root, 0, y);

        if (xNode.first == yNode.first) return false;
        if (xNode.second != yNode.second) return false;
        return true;
    }

    pair<TreeNode*, int> findNode(TreeNode* parent, TreeNode* cur, int depth, const int& val){
        if (cur == nullptr) return {parent, -1};
        if (cur->val == val) return make_tuple(parent, depth);
        auto left = findNode(cur, cur->left, depth + 1, val);
        auto right = findNode(cur, cur->right, depth + 1, val);

        if (left.second == -1 && right.second == -1) return {cur, -1};
        else if (left.second == -1) return right;
        else return left;
    }
};