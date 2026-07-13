// Last updated: 13/07/2026, 22:20:06
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int cur = num;
        
        string result = "";
        string hexCoding = "0123456789abcdef";

        while (cur){
            result += hexCoding[cur % 16];
            cur /= 16;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};