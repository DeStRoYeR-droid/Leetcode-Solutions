// Last updated: 07/09/2026, 22:37:03
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = 'z' - 'A';
        vector<bool> mp(n, false);

        for (const char& ch : word){
            mp[ch - 'A'] = true;
        }
        int result = 0;
        for (int i = 0; i < 26; ++i){
            result += mp[i] && mp[i + 'a' - 'A'];
        }
        return result;
    }
};