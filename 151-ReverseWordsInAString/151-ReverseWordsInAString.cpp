// Last updated: 13/07/2026, 22:25:42
class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string cur_word = "";
        for (char& ch : s){
            if (ch == ' '){
                if (cur_word.length()){
                    result = " " + cur_word+ result;
                    cur_word = "";
                }
                
            }
            else{
                cur_word += ch;
            }
        }
        result = (cur_word.length()) ? cur_word + result : result.substr(1, result.length());
        return result;
    }
};