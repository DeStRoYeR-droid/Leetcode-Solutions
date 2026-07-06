// Last updated: 06/07/2026, 18:57:30
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        bool hasDigit = false, hasUpper = false, hasLower = false, hasSpecial = false;
        char last = ' ';
        static const string special = "!@#$%^&*()-+";
        for (const char& ch : password){
            if (ch == last) return false;
            if (isdigit(ch)) hasDigit = true;
            else if (special.find(ch) != string::npos) hasSpecial = true;
            else if ('a' <= ch && ch <= 'z') hasLower = true;
            else if ('A' <= ch && ch <= 'Z') hasUpper = true;
            last = ch;
        }
        return hasDigit && hasUpper && hasLower && hasSpecial;
    }
};