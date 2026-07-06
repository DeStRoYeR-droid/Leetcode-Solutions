// Last updated: 06/07/2026, 19:06:56
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int sum = 0;
        return rangeSumBST2(root, low, high, sum) ;
    }
    int rangeSumBST2(TreeNode* root, int low, int high, int& sum){
        if (root == nullptr) return sum;
        else if (root->val > high){
            return rangeSumBST2(root->left, low, high, sum);
        }
        else if (root->val < low){
            return rangeSumBST2(root->right, low, high, sum);
        }
        else{
            sum += root->val;
            rangeSumBST2(root->right , low, high, sum);
            rangeSumBST2(root->left, low, high, sum);
            return sum;
        }
    }
};