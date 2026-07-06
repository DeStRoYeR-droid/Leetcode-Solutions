// Last updated: 06/07/2026, 18:57:22
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