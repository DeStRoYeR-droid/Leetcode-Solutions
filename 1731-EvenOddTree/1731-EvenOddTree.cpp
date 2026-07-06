// Last updated: 06/07/2026, 19:01:56
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int curLevel = 1;

        while (!q.empty()){
            int sz = q.size();
            int last = -1;
            for (int i = 0; i < sz; ++i){
                TreeNode* node = q.front(); q.pop();
                if (node->val % 2 ^ curLevel % 2) return false;


                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
                if (last == -1) {
                    last = node->val;
                    continue;
                }
                if (curLevel % 2){
                    if (node->val <= last){
                        return false;
                    }
                }
                else if (node->val >= last){
                    return false;
                }

                last = node->val;

            }
            curLevel = 1 - curLevel;
        }
        return true;
    }
};