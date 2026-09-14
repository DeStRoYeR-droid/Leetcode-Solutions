// Last updated: 14/09/2026, 09:27:27
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for (const char& ch : text) freq[ch - 'a']++;
        return min({freq['a' - 'a'], freq['b' - 'a'], freq['l' - 'a'] / 2, freq['o' - 'a'] / 2, freq['n' - 'a']});
    }
};