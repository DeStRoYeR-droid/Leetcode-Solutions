// Last updated: 14/09/2026, 09:15:22
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        short arr[26] = {0};
        short length = words.size();
        for (string& word: words) for (char& ch : word) arr[ch - 'a']++;
        for (short& i : arr) if (i % length) return false;
        return true;
    }
};