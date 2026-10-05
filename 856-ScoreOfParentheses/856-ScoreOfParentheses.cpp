// Last updated: 05/10/2026, 15:01:27
class Solution {
public:
    int scoreOfParentheses(string s) {
        int result = 0;
        int depth = 0;
        for (int i = 0; i < (int)s.size(); ++i){
            if (s[i] == '('){
                ++depth;
            }
            else {
                --depth;
                if (s[i - 1] == '('){
                    result += 1 << depth;
                }
            }
        }
        return result;
    }
};