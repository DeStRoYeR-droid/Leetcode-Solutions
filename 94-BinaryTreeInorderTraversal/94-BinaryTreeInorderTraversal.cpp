// Last updated: 13/07/2026, 22:27:44
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
    vector<int> inorderTraversal(TreeNode* root) {
        #include <stack>
        vector<int> result;
        stack<TreeNode*> nodes;
        TreeNode* cur = root;

        while (cur != NULL || !nodes.empty()){
            while (cur != NULL){
                nodes.push(cur);
                cur = cur->left;
            }

            cur = nodes.top();
            nodes.pop();

            result.push_back(cur->val);
            cur = cur->right;
        }

        return result;
    }
};