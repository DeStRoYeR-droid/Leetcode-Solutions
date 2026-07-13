// Last updated: 13/07/2026, 22:30:37
class Solution {
public:
    int myAtoi(string s) {
        int result = 0, i = 0, sign = 1;
        while (s[i] == ' ') i++;
        
        if (i < s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.size() && isdigit(s[i])){
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] > '7'))
                return sign == -1 ? INT_MIN : INT_MAX;
            
            result = result * 10 + (s[i] - '0');
            i++;
        }
        return result * sign;
    }
};