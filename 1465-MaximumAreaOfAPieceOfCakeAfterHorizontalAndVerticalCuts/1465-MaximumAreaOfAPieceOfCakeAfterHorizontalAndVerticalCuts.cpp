// Last updated: 14/09/2026, 09:21:42
static const int MOD = 1e9 + 7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int maxH = horizontalCuts[0];
        int maxV = verticalCuts[0];

        int n = horizontalCuts.size(), m = verticalCuts.size();
        for (int i = 1; i < max(n, m); ++i){
            if (i < n){
                maxH = max(maxH, horizontalCuts[i] - horizontalCuts[i - 1]);
            }
            if (i < m){
                maxV = max(maxV, verticalCuts[i] - verticalCuts[i - 1]);
            }
        }
        return (1LL * maxH * maxV) % MOD;
    }
};