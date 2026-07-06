// Last updated: 06/07/2026, 18:48:48
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        const int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; ++i){
            set<int> odd, even;
            for (int j = i; j < n; ++j){
                if (nums[j] % 2) odd.insert(nums[j]);
                else even.insert(nums[j]);

                if (odd.size() == even.size()) result = max(result, j - i + 1);
            }
        }
        return result;
    }
};