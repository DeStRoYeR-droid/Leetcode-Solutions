// Last updated: 06/07/2026, 18:52:53
class Solution {
public:
    int minimumLength(string s) {
        ios::sync_with_stdio(0); cin.tie(0);
        int freq[26] = {0};
        
        for (const char& ch : s) freq[ch - 'a']++;
        for (int i = 0; i < 26; i++){
            while (freq[i] > 2)
                freq[i] -= 2;
        }
        return std::accumulate(freq, freq + 26, 0);
    }
};