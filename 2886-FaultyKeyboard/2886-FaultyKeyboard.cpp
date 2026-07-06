// Last updated: 06/07/2026, 18:54:55
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