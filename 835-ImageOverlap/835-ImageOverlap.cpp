// Last updated: 14/09/2026, 09:34:18
using pii = pair<int, int>;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        set<pii> m1, m2;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (img1[i][j]) m1.insert({i, j});
                if (img2[i][j]) m2.insert({i, j});
            }
        }
        int result = 0;
        map<int, int> freq;
        for (auto [r1, c1] : m1){
            int cur = 0;
            for (auto [r2, c2]: m2){
                int dr = r1 - r2;
                int dc = c1 - c2;
                result = max(result, ++freq[dr * 37 + dc]);
            }
        }
        return result;
    }
};