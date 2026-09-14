// Last updated: 14/09/2026, 09:14:20
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