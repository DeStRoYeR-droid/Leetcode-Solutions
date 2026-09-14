// Last updated: 14/09/2026, 09:19:04
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
