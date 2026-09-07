// Last updated: 07/09/2026, 22:42:53
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string maxStr = s, minStr = s;
        for (char& c : s){
            if (c != '9'){
                for (char& ch : maxStr) if (ch == c) ch = '9';
                break;
            }
        }

        for (char& c : s){
            if (c != 0){
                for (char& ch : minStr) if (ch == c) ch = '0';
                break;
            }
        }

        return stoi(maxStr) - stoi(minStr);
    }
};