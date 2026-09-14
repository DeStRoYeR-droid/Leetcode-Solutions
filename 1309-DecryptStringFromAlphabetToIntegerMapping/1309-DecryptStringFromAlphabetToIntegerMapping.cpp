// Last updated: 14/09/2026, 09:25:14
class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int value = 0, i = s.size() - 1;
        while (i >= 0){
            char cur = s[i];
            if (cur == '#'){
                value = stoi(s.substr(i - 2, i));
                result = char ('a' + value - 1) + result;
                i -= 3;
            }
            else{
                result = char ('a' + (cur - '1')) + result;
                --i;
            }
        }
        return result;
    }
};