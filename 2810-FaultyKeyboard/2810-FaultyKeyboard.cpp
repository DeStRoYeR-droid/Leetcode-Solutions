// Last updated: 07/09/2026, 22:41:24
class Solution {
public:
    string finalString(string s) {
        string result = "";
        for (const char& ch : s){
            if (ch == 'i') reverse(result.begin(), result.end());
            else result += ch;
        }
        return result;
    }
};