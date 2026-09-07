// Last updated: 07/09/2026, 22:38:57
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> occur(26, 0);
        for (const char& ch : word) occur[ch - 'a']++;
        sort(occur.rbegin(), occur.rend());

        int result = 0;
        for (int i = 0; i < 26; ++i){
            result += occur[i] * (1 + i / 8);
        }
        return result;  
    }
};