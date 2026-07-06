// Last updated: 06/07/2026, 18:56:55
class Solution {
public:
    string removeStars(string s) {
        int i = 0, j = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '*') j--;
            else s[j++] = s[i];
        }
        return s.substr(0, j);
    }
};