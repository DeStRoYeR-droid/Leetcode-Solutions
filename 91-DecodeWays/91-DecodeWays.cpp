// Last updated: 13/07/2026, 22:27:49
class Solution {
public:
    int numDecodings(string s) {
        const int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        if (n == 1) return 1;

        int prevOne = 1, prevTwo = 0;

        for (int i = 1; i <= n; ++i){
            int oneDigit = s[i - 1] - '0';
            
            int current = 0;

            if (oneDigit != 0) current += prevOne;
            if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
                current += prevTwo;
            }

            prevTwo = prevOne;
            prevOne = current;
        }
        return prevOne;
    }
};