// Last updated: 13/07/2026, 22:19:16
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long stepsRequired = INT_MAX;
        for (const auto& val : nums){
            long long picked = val, cur = 0;
            for (const auto& val2 : nums) cur += abs(picked - val2);
            stepsRequired = min(stepsRequired, cur);
        } 
        return stepsRequired;
    }
};