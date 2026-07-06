// Last updated: 06/07/2026, 18:47:33
class Solution {
public:
    string largestEven(string s) {
        int r = s.size() - 1;
        while (r >= 0){
            if ((s[r] - '0') % 2 == 0) break;
            --r;
        }
        return s.substr(0, r + 1);
    }
};