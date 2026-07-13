// Last updated: 13/07/2026, 22:20:31
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for (const char& ch : ransomNote) freq1[ch - 'a']++;
        for (const char& ch : magazine) freq2[ch - 'a']++;

        for (int i = 0; i < 26; i++){
            if (freq1[i] > freq2[i]) return false;
        }
        return true;
    }
};