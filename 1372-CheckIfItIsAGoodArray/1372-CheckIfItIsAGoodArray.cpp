// Last updated: 06/07/2026, 19:04:43
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