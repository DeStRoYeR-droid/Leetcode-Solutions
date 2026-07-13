// Last updated: 13/07/2026, 22:21:07
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long coverage = 1;
        int result = 0;
        size_t cur_index = 0;

        while (coverage <= n){
            if (cur_index < nums.size() && nums[cur_index] <= coverage) 
                coverage += nums[cur_index++];
            else{
                result++;
                coverage <<= 1;
            }
        }

        return result;
    }
};