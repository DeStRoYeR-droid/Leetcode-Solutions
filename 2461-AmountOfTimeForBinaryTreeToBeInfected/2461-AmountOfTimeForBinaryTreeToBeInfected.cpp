// Last updated: 06/07/2026, 18:56:57
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
    int maxDistance = 0;
    int amountOfTime(TreeNode* root, int start) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        trav(root , start);
        return maxDistance;
    }
    int trav(TreeNode* root , int start){
        int depth = 0;
        if (root == nullptr) return depth;

        int leftDepth = trav(root->left , start);
        int rightDepth = trav(root->right , start);

        if (root->val == start){
            maxDistance = max(leftDepth , rightDepth);
            depth = -1;
        }
        else if (leftDepth >= 0 && rightDepth >= 0){
            depth = max(leftDepth , rightDepth) + 1;
        }
        else{
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance , distance);
            depth = min(leftDepth , rightDepth) - 1;
        }
        return depth;
    }
};