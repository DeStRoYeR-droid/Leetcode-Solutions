// Last updated: 06/07/2026, 19:01:06
class Solution {
public:
    bool isNice(string& s){
        int small = 0;
        int capital = 0;
        for (char& ch : s){
            if (ch - 'a' >= 0) small |= (1 << (ch - 'a'));
            else capital |= (1 << (ch - 'A'));
        }
        return (capital == small);
    }
    string longestNiceSubstring(string s) {
        const int length = s.length();
        string result = "";
        for (int i = 0; i < length; i++){
            for (int j = 2; j <= length - i; j++){
                string cur = s.substr(i, j);
                // cout << cur << " " << isNice(cur) << endl;
                if (isNice(cur)){
                    result = (result.length() >= cur.length()) ? result : cur;
                }
            }
        }
        return result;
    }
};