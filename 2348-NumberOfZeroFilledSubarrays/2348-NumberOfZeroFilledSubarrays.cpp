// Last updated: 07/09/2026, 22:46:26
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;
        int index = 0;
        const int n = nums.size();
        while (index < n){
            if (nums[index] == 0){
                long long num = 0;
                while (index < n && nums[index] == 0){
                    ++num;
                    ++index;
                }
                result += (num * (num + 1)) / 2;
            }
            else ++index;
        }
        return result;
    }
};