// Last updated: 13/07/2026, 22:19:06
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "";
        for (const char& ch : s){
            if (isalpha(ch) || '0' <= ch && ch <= '9'){
                if ('a' <= ch && ch <= 'z') temp += (ch - 'a' + 'A');
                else temp += ch;
            }
        }
        reverse(temp.begin(), temp.end());
        int n = temp.size(), i = 0;
        string result = "";

        while (i < n){
            result += temp.substr(i, k);
            if (i + k < n) result += "-";
            i += k;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};