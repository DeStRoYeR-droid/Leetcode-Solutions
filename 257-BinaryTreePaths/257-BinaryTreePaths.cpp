// Last updated: 13/07/2026, 22:22:09
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, result, "");
        return result;
    }
    void dfs(TreeNode* head, vector<string>& result, string cur){
        if (head == nullptr) return;
        if (head->left == nullptr && head->right == nullptr)
            result.push_back(cur + to_string(head->val));

        else{
            cur += to_string(head->val) + "->";
            dfs(head->left, result, cur);
            dfs(head->right, result, cur);
        }
    }
};