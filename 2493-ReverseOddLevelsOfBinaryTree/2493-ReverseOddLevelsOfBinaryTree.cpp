// Last updated: 06/07/2026, 18:56:45
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        bool reverse = 0;

        while (!bfs.empty()){
            int q_size = bfs.size();
            vector<TreeNode*> arr(q_size);

            for (int i = 0; i < q_size; i++){
                auto node = bfs.front();
                bfs.pop();

                if (node->left){ 
                    bfs.push(node->left); 
                }
                if (node->right){
                    bfs.push(node->right);
                }

                if (reverse){
                    arr[i] = node;
                    if (i >= (q_size / 2)){
                        swap(arr[i]->val, arr[q_size - (i + 1)]->val);
                    }
                }
            }
            reverse = !reverse;
        }
        return root;
    }
};