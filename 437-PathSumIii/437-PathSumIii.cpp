// Last updated: 13/07/2026, 22:19:44
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
private:
    int solve(TreeNode* root, long long sum, int target, map<long long, int>& mp){
        if (root == nullptr) return 0;
        sum += root->val;
        int count = mp[sum - target];
        mp[sum]++;
        
        count += solve(root->left, sum, target, mp);
        count += solve(root->right, sum, target, mp);

        mp[sum]--;
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        map<long long, int> mp;
        mp[0] = 1;
        return solve(root, 0, targetSum, mp);
    }
};