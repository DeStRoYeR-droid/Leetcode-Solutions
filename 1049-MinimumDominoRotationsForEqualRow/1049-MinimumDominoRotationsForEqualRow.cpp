// Last updated: 06/07/2026, 19:06:25
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int n = tops.size();
        int result = INT_MAX;
        
        for (int i = 1; i <= 6; ++i){
            bool allContains = true;
            int topCount = 0, bottomCount = 0;
            
            for (int j = 0; j < n; ++j){
                if (tops[j] != i && bottoms[j] != i){
                    allContains = false;
                    break;
                }
                if (tops[j] == i) ++topCount;
                if (bottoms[j] == i) ++bottomCount;
            }

            if (allContains) result = min(result, n - max(topCount, bottomCount));
        }

        result = (result == INT_MAX) ? -1 : result;
        return result;
    }
};