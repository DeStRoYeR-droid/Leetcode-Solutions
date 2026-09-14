// Last updated: 14/09/2026, 09:18:54
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1 = "";
        string string2 = "";

        for (string& str : word1) string1 += str;
        for (string& str : word2) string2 += str;

        return string1 == string2;
    }
};