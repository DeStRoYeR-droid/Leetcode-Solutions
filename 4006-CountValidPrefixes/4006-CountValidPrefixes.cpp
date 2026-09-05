// Last updated: 05/09/2026, 16:37:21
class Solution {
public:
    int countValidPrefixes(string s) {
        int c_1 = 0, c_0 = 0;
        int result = 0;
        for (const char& c : s){
            c_1 += (c == '1');
            c_0 += (c == '0');

            result += (bool)(abs(c_0 - c_1) <= 1);
        }
        return result;
    }
};