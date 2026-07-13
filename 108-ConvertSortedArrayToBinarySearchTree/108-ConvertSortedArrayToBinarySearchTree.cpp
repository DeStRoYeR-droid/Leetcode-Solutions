// Last updated: 13/07/2026, 22:27:06
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode* helper(const vector<int>& nums, int left, int right){
        if (left > right){
            return nullptr;
        }
        int mid = left + (right - left) / 2;
        return new TreeNode(
            nums[mid],
            helper(nums, left, mid -1),
            helper(nums, mid + 1, right)
        );
    }
};