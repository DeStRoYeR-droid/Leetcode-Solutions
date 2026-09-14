// Last updated: 14/09/2026, 09:15:16
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - i; i >= 0; --i){
            if (num[i] % 2) return num.substr(0, i + 1);
        }
        return "";
    }
};