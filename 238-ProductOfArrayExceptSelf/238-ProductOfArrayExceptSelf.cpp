// Last updated: 13/07/2026, 22:22:25
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int len = nums.size();
        vector<int> result(len, 1);
        int pre = 1, post = 1;
        for (int i = 0; i < len; ++i){
            result[i] = pre;
            pre *= nums[i];
        }
        for (int i = len - 1; i > -1; --i){
            result[i] *= post;
            post *= nums[i];
        }
        return result;
    }
};