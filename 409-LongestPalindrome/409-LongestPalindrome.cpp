// Last updated: 13/07/2026, 22:20:03
class Solution {
public:
    int longestPalindrome(string s) {
        long long state = 0;
        int result = 0;
        for (const char& ch : s){
            if (state & (1LL << (ch - 'A'))){
                result += 2;
                state = state ^ (1LL << (ch - 'A'));
            }
            else {
                state |= 1LL << (ch - 'A');
            }
        }
        if (state) ++result;
        return result;
    }
};