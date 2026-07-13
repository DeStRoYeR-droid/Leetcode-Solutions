// Last updated: 13/07/2026, 22:27:28
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool ltr = true;
        while (!q.empty()){
            int size = q.size();
            vector<int> row;
            row.reserve(size);

            while (size--){
                TreeNode* cur = q.front(); q.pop();
                row.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (!ltr) reverse(row.begin(), row.end());
            result.push_back(row);

            ltr = !ltr;
        }
        return result;
    }
};