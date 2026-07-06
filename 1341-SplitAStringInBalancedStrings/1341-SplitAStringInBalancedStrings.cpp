// Last updated: 06/07/2026, 19:04:58
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = (s[0] == 'R') ? 1 : -1;
        int result = 0;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == 'R') count++;
            else count--;
            if (count == 0) result++;
        }
        return result;
    }
};