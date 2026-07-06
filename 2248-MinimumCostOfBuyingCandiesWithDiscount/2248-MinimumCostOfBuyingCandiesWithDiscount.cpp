// Last updated: 06/07/2026, 18:58:30
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int result = 0;
        sort(cost.begin(), cost.end());
        int i = cost.size() - 1;
        while (i > 1){
            result += cost[i] + cost[i - 1];
            i -= 3;
        }
        for (int j = 0; j <= i; ++j){
            result += cost[j];
        }
        return result;
    }
};