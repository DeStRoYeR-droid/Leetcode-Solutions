// Last updated: 07/09/2026, 22:32:39
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