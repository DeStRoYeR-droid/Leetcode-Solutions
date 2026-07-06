// Last updated: 06/07/2026, 18:53:11
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lL(26, -1), fU(26, -1);
        for (int i = 0; i < word.size(); i++){
            char ch = word[i];
            if (ch - 'a' >= 0) lL[ch - 'a'] = i;
            else if (fU[ch - 'A'] == -1) fU[ch - 'A'] = i;
        }
        int result = 0;
        for (int i = 0; i < 26; ++i){
            if (lL[i] == -1 || fU[i] == -1) continue;
            if (lL[i] > fU[i]) continue;
            else ++result;
        }
        
        return result;
    }
};