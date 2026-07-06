// Last updated: 06/07/2026, 19:00:06
class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.size() - i; i >= 0; --i){
            if (num[i] % 2) return num.substr(0, i + 1);
        }
        return "";
    }
};