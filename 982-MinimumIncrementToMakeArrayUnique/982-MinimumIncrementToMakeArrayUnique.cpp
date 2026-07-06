// Last updated: 06/07/2026, 19:06:51
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        cin.tie(NULL);
        cout.tie(NULL);
        sort(nums.begin(), nums.end());
        int result = 0;
        int prev = -1;
        for (int& num : nums){
            if (num <= prev) {
                result += prev - num + 1;
                num += prev - num + 1;
            }
            prev = num;
        }
        return result;
    }
};