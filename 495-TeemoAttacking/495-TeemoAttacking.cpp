// Last updated: 13/07/2026, 22:18:55
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        int last = -1;
        for (const int& val : timeSeries){
            if (val > last) result += duration;
            else result += val - last + duration;
            last = val + duration;
        }
        return result;
    }
};