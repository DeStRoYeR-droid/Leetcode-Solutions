// Last updated: 06/07/2026, 19:00:43
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int n = nums.size();
        int result = 0;
        int cur = 0;
        int cur_sum = 0;
        
        for (const int& num : nums){
            if (num > cur){
                cur_sum += num;
            }
            else{
                result = max(cur_sum, result);
                cur_sum = num;
            }
            cur = num;
        }

        return max(result, cur_sum);
    }
};