// Last updated: 13/07/2026, 22:18:47
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool negative = (num < 0);
        string result = "";
        num = abs(num);
        while (num > 0){
            result = to_string(num % 7) + result;
            num /= 7;
        }
        if (negative) result = '-' + result;
        return result;
    }
};