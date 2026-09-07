// Last updated: 07/09/2026, 22:49:32
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long curMax = 0, cur = 0, curMin = 0;
        for (const int& val : differences){
            cur += val;
            curMax = max(curMax, cur);
            curMin = min(curMin, cur);
        }

        int result = max(upper - lower + 1 - curMax + curMin, 0L);
        return result;
    }
};