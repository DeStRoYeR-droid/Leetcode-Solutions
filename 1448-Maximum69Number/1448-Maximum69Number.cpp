// Last updated: 06/07/2026, 19:04:04
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); ++i){
            if (s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};