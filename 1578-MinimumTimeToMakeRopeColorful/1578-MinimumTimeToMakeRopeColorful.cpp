// Last updated: 14/09/2026, 09:19:49
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        const int n = colors.size();
        int prev = 0;
        int result = 0;

        for (int i = 1; i < n; ++i){
            if (colors[i] == colors[i - 1]){
                result += min(neededTime[i], neededTime[prev]);
                if (neededTime[i] > neededTime[prev]) prev = i;
            }
            else prev = i;
        }
        return result;
    }
};