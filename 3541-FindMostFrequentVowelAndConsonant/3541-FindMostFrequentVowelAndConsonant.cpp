// Last updated: 07/09/2026, 22:29:38
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (const char& ch : s){
            freq[ch - 'a']++;
        }

        int maxConsonant = 0, maxVowel = 0;
        for (int i = 0; i < 26; ++i){
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) maxVowel = max(maxVowel, freq[i]);
            else maxConsonant = max(maxConsonant, freq[i]);
        }

        return maxVowel + maxConsonant;
    }
};