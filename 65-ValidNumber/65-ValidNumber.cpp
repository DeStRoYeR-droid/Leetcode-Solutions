// Last updated: 13/07/2026, 22:28:43
class Solution {
public:
    bool isNumber(string s) {
        const int n = s.size();
        bool isDot = false, result = false, ise = false;

        for (int i = 0; i < n; ++i){
            if (isdigit(s[i])) result = true;
            else if (s[i] == '+' || s[i] == '-'){
                if (i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) return false;
            } else if (s[i] == 'e' || s[i] == 'E'){
                if (ise || !result) return false;
                ise = true;
                result = false;
            } else if (s[i] == '.'){
                if (isDot || ise) return false;
                isDot = true;
            } else return false;
        }
        return result;
    }
};