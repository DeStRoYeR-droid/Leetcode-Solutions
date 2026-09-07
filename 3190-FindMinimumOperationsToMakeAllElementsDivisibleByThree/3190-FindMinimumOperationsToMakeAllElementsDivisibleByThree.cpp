// Last updated: 07/09/2026, 22:36:12
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result = 0;
        for (const int& val : nums){
            if (val % 3) ++result;
        }
        return result;
    }
};