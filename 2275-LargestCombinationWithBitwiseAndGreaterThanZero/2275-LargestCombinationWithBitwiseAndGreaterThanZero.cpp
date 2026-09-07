// Last updated: 07/09/2026, 22:47:55
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for (int i = 0; i < 24; i++){ // 24 = max set btis
            int cur = 0;
            for (int& candidate : candidates)
                cur += (candidate & 1 << i) != 0;
            ans = max(ans, cur);
        }
        return ans;
    }
};