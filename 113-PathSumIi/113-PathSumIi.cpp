// Last updated: 13/07/2026, 22:26:52
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> state;
        makePaths(root, 0, targetSum, state, result);
        return result;
    }

    void makePaths(TreeNode* cur, int curSum, int& target, vector<int> state, vector<vector<int>>& result){
        if (cur == nullptr) return;
        curSum += cur->val;
        state.push_back(cur->val);
        if (cur->left == nullptr && cur->right == nullptr){
            if (curSum == target)
                result.push_back(state);
            else return;
        }
        else{
            makePaths(cur->left, curSum, target, state, result);
            makePaths(cur->right, curSum, target, state, result);
        }
    }
};