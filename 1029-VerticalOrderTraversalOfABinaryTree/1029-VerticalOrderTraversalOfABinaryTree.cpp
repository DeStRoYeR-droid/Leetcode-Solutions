// Last updated: 06/07/2026, 19:06:33
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> levels;
        traverse(root, 0, levels);
        vector<vector<int>> result;
        for (auto [_, row] : levels){
            result.push_back(row);
        }
        return result;
    }

    void traverse(TreeNode* root, int verticalLevel, map<int, vector<int>>& result){
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()){
            int n = q.size();
            map<int, vector<int>> mp;
            for (int i = 0; i < n; ++i){
                auto [cur, order] = q.front(); q.pop();
                mp[order].push_back(cur->val);
                if (cur->left) q.push({cur->left, order - 1});
                if (cur->right) q.push({cur->right, order + 1});
            }

            for (auto [order, row] : mp){
                sort(row.begin(), row.end());
                result[order].insert(result[order].end(), row.begin(), row.end());
            }
        }
    }
};