// Last updated: 06/07/2026, 18:48:42
class Solution {
public:
    bool scoreBalance(string s) {
        int right = 0;
        for (const char& ch : s) right += ch - 'a' + 1;
        int left = 0;
        for (const char& ch : s){
            if (left == right) return true;
            left += ch - 'a' + 1;
            right -= ch - 'a' + 1;
        }
        return false;
    }
};