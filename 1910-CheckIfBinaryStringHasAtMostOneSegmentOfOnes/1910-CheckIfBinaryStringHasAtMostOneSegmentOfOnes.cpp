// Last updated: 06/07/2026, 19:00:56
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