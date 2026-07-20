// Last updated: 20/07/2026, 17:17:18
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int xC = 0;
        int yC = 0;
        for (const char& ch : s){
            xC += (ch == x);
            yC += (ch == y);
        }
        string result;
        result.reserve(s.size());
        for (int i = 0; i < yC; ++i) result += y;
        for (int i = 0; i < xC; ++i) result += x;
        for (const char& ch : s){
            if (ch != x && ch != y) result += ch;
        }
        return result;
    }
};