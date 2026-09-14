// Last updated: 14/09/2026, 09:26:19
class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int hcf = nums[0];
        for (const int& num : nums){
            hcf = __gcd(hcf, num);
        }
        return hcf == 1;
    }
};