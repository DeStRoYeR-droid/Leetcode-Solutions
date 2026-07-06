// Last updated: 06/07/2026, 19:05:35
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        int result = 0;
        for (const auto& domino : dominoes){
            int mini = min(domino[0], domino[1]);
            int maxi = max(domino[0], domino[1]);
            ++mp[10 * maxi + mini];
        }

        for (const auto& val : mp) if (val.second > 1) result += val.second * (val.second - 1) / 2;
        return result;
    }
};