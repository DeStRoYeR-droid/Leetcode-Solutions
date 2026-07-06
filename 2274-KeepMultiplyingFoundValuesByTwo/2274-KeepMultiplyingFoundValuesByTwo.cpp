// Last updated: 06/07/2026, 18:58:16
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