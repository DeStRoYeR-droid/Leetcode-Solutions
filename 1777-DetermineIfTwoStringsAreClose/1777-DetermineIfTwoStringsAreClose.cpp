// Last updated: 06/07/2026, 19:01:44
class Solution {
    int letters1[26] , letters2[26];
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int length = word1.length();
        if (length != word2.length()) return false;
        
        for (int i = 0; i < length; i++){
            letters1[word1[i] - 'a']++;
            letters2[word2[i] - 'a']++;
        }

        // Check for characters which are in one but not in another
        for (int i = 0; i < 26; i++)
            if (letters1[i] > 0 ^ letters2[i] > 0) return false;

        sort(letters1 , letters1+26);
        sort(letters2 , letters2+26);

        for (int i = 0; i < 26; i++)
            if (letters1[i] != letters2[i]) return false;

        return true;
    }
};