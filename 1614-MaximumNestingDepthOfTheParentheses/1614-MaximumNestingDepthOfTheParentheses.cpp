// Last updated: 30/09/2026, 18:27:15
class Solution {
public:
    int maxDepth(string s) {
        int result = 0;
        int cur_level = 0;
        for (const char& ch : s){
            if (ch == '(') ++cur_level;
            else if (ch == ')') --cur_level;
            result = max(result, cur_level);
        }
        return result;
    }
};