// Last updated: 14/09/2026, 09:30:29
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, result = 0, zeroCount = 0;
        for (int right = 0; right < nums.size(); right++){
            if (nums[right] == 0) zeroCount++;
            
            while (zeroCount > k){
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};