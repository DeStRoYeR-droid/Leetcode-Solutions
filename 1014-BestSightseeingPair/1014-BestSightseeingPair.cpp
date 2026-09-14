// Last updated: 14/09/2026, 09:30:11
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = 0;
        int prev = values[0];
        for (int j = 1; j < values.size(); j++){
            result = max(result, prev + values[j] - j);
            prev = max(prev, values[j] + j);
        }
        return result;
    }
};