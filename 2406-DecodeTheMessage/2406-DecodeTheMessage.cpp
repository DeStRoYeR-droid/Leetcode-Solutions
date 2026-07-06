// Last updated: 06/07/2026, 18:57:20
class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> mapping(26, ' ');
        string result = "";
        int i = 0;
        for (char ch : key){
            if ('a' <= ch && ch <= 'z'){
                if (mapping[ch -'a'] == ' '){
                    mapping[ch - 'a'] = 'a' + i;
                    ++i;
                }
            }
        }

        for (const char& ch : message){
            if ('a' <= ch && ch <= 'z'){
                result += mapping[ch - 'a'];
            }
            else result += ch;
        }

        return result;
    }
};