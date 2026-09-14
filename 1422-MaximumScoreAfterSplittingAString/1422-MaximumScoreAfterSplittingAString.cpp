// Last updated: 14/09/2026, 09:22:33
class Solution {
public:
    int maxScore(string s) {
        int left = 0;
        int right = count(s.begin(), s.end(), '1');

        int result = 0;
        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] == '0') left++;
            else right--;
            result = max(result, left + right);
        }
        return result;
    }
};