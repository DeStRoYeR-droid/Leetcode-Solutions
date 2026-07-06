// Last updated: 06/07/2026, 19:01:46
class Solution {
public:
    int minimumDeletions(string s) {
        int result = 0, b = 0;
        for (char& c : s) {
            if (~c & 1) b++;
            else if (b) {
                result++;
                b--;
            }
        }
        return result;
    }
};
