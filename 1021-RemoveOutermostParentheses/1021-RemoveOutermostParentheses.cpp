// Last updated: 15/10/2026, 11:14:16
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int level = 0;

        for (const char& c : s){
            if (c == '('){
                if (level > 0){
                    result += c;
                }
                ++level;
            }
            else {
                --level;
                if (level > 0) result += c;
            }
        }
        return result;
    }
};