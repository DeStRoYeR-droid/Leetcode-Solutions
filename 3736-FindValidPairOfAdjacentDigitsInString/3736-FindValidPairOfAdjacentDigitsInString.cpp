// Last updated: 06/07/2026, 18:51:15
class Solution {
public:
    string findValidPair(string s) {
        map<char, int> freq;
        int cur, prev;
        string result = "";
        for (const char& ch : s) freq[ch]++;

        for (int i = 1; i < s.size(); ++i){
            if (s[i] == s[i-1]) continue;
            
            if (freq[s[i]] == s[i] - '0' && freq[s[i-1]] == s[i-1] - '0'){
                result = {s[i-1], s[i]};
                break;
            }
        }
        return result;
    }
};