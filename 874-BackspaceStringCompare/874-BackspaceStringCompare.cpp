// Last updated: 06/07/2026, 19:07:47
class Solution {
public:
    bool backspaceCompare(string& s, string&  t) {
        int index = 0;
        for (char& ch : s){
            if (ch == '#') index = max(0, index - 1);
            else s[index++] = ch;
        }
        s = s.substr(0, index);
        
        index = 0;
        for (char& ch : t){
            if (ch == '#') index = max(0, index - 1);
            else t[index++] = ch;
        }

        t = t.substr(0, index);
        return s == t;
    }
};