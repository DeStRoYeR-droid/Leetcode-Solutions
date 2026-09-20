// Last updated: 20/09/2026, 10:29:53
class Solution {
public:
    long long countPairs(vector<string>& words) {
        if (words.size() <= 1) return 0;
        unordered_map<string, long long> mp;
        for (const string& str : words){
            string pattern = "";
            for (int i = 0; i < str.size() - 1; ++i){
                pattern += 'a' + (str[i + 1] - str[i] + 26) % 26;
            }
            ++mp[pattern];
        }
        long long result = 0;
        for (auto [m, f]: mp){
            if (f >= 2){
                result += f * (f - 1) / 2;
            }
        }
        return result;
    }
};