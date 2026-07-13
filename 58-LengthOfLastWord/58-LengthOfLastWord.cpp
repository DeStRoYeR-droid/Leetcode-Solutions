// Last updated: 13/07/2026, 22:28:53
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int i = s.length() - 1;
        while (s[i] == ' ') i--;

        for (i; i >= 0; i--){
            if (s[i] == ' ') break;
            else result++;
        }

        return result;

    }
};