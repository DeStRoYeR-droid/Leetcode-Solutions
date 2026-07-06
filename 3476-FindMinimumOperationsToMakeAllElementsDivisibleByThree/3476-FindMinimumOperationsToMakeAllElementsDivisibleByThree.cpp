// Last updated: 06/07/2026, 18:52:44
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