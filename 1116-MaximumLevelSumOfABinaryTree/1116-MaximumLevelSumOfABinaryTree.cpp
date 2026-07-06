// Last updated: 06/07/2026, 19:06:02
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int val = INT_MIN;
        int result = 0;
        int level = 0;
        while (!q.empty()){
            const int size = q.size();
            int cur = 0;
            for (int i = 0; i < size; ++i){
                TreeNode* node = q.front();
                q.pop();

                cur += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
            if (cur > val){
                result = level;
                val = cur;
            }
        }
        return result;
    }
};