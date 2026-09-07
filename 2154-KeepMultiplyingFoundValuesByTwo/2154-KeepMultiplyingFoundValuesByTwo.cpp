// Last updated: 07/09/2026, 22:49:07
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> vals(nums.begin(), nums.end());
        
        while (vals.find(original) != vals.end()){
            original <<= 1;
        }
        return original;
    }
};