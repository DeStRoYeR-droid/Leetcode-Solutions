// Last updated: 06/07/2026, 19:06:10
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
    int i = 0;
    TreeNode* recoverFromPreorder(string& traversal, int depth = 0) {
        if (i >= traversal.size()) return nullptr;
        int D = 0;
        while (traversal[i] == '-') D++, i++;
        if (D < depth){
            i -= D;
            return nullptr;
        }

        int x = 0;
        while (isdigit(traversal[i])){
            x = x * 10 + (traversal[i] - '0');
            i++;
        }

        TreeNode* node = new TreeNode(x);

        node->left = recoverFromPreorder(traversal, depth + 1);
        node->right = recoverFromPreorder(traversal, depth + 1);

        return node;
    }
};