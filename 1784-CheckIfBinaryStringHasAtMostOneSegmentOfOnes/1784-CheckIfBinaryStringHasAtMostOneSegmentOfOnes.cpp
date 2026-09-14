// Last updated: 14/09/2026, 09:17:08
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool ones = true;
        for (const char& ch : s){
            if (ch == '1' && !ones) return false;
            if (ch == '0') ones = false;
        }
        return true;
    }
};