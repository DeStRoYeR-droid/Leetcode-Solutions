// Last updated: 06/07/2026, 18:47:56
class Solution {
public:
    int minimumFlips(int n) {
        string s = "";
        while (n){
            s += '0' + n % 2;
            n /= 2;
        }
        int result = 0;
        for (int l = 0, r = s.size() - 1; r >= 0; ++l, --r){
            if (s[l] != s[r]) ++result;
        }
        return result;
    }
};