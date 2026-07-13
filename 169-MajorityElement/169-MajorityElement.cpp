// Last updated: 13/07/2026, 22:25:07
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for (int& num : nums){
            if (count == 0) candidate = num;

            if (num == candidate) count++;
            else count--;
        }
        return candidate;
    }
};