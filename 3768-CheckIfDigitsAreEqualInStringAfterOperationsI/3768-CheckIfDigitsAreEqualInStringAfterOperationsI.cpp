// Last updated: 06/07/2026, 18:50:57
class Solution {
public:
    bool hasSameDigits(string s) {
        string temp;
        while (s.size() > 2){
            temp = "";
            for (int i = 0; i < s.size() - 1; ++i){
                temp += '0' + ((s[i] - '0') + (s[i+1] - '0')) % 10;
            }
            s = temp;
        }
        return s[0] == s[1];
    }
};