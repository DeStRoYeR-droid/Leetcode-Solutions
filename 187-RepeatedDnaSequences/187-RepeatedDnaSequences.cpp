// Last updated: 13/07/2026, 22:24:22
#include <string_view>

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.size() <= 10) return result;

        unordered_map<string_view, int> freq;
        for (size_t i = 0; i <= s.length() - 10; ++i) {
            string_view window(s.data() + i, 10);
            freq[window]++;
        }

        for (const auto&[s, v] : freq){
            if (v >= 2){
                result.emplace_back(s);
            }
        }
        return result;
    }
};