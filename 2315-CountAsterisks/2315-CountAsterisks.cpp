// Last updated: 07/09/2026, 22:47:01
class Solution {
public:
    int countAsterisks(string s) {
        bool canCount = true;
        int result = 0;
        for (const char& ch : s){
            if (ch == '|') canCount = !canCount;
            else if (ch == '*') result += canCount;
        }
        return result;
    }
};