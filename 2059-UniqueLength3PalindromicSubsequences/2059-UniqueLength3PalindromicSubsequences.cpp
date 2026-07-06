// Last updated: 06/07/2026, 18:59:52
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        const int n = s.size();
        vector<pair<int, int>> mapping(26, {-1, -1});

        for (int i = 0; i < n; ++i){
            int index = s[i] - 'a';
            if (mapping[index].first == -1) mapping[index].first = i;
            mapping[index].second = i;
        }

        int result = 0;
        for (int i = 0; i < 26; ++i){
            int l = mapping[i].first, r = mapping[i].second;
            int mask = 0;
            for (int j = l + 1; j < r; ++j){
                mask = mask | (1 << (s[j] - 'a'));
            }
            result += __builtin_popcount(mask);
        }
        return result;
    }
};