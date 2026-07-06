// Last updated: 06/07/2026, 18:47:52
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long result = 0, total = 0;
        string str = to_string(n);
        for (const char& ch : str){
            if (ch != '0'){
                result = result * 10 + (ch - '0');
                total += ch - '0';
            }
        }
        return result * total;
    }
};