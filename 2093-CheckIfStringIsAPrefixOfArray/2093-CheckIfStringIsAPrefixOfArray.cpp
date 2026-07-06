// Last updated: 06/07/2026, 18:59:42
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string cur = "";
        for (string& word : words){
            if (s == cur) return true;
            cur += word;
        }
        return cur == s;
    }
};