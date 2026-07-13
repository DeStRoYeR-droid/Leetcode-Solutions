// Last updated: 13/07/2026, 22:23:29
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        string combined = s + "#" + rev;
        const int n = combined.size();

        vector<int> kmp(n, 0);
        buildKMP(combined, n, kmp);

        int palindrome_len = kmp[n - 1];
        string non_palindrome = s.substr(palindrome_len);

        reverse(non_palindrome.begin(), non_palindrome.end());
        return non_palindrome + s;
    }

    void buildKMP(string combined, int n, vector<int>& kmp){
        int j = 0;
        kmp[0] = 0;

        for (int i = 1; i < n; ++i){
            if (combined[i] == combined[j]){
                ++j;
                kmp[i] = j;
            }
            else{
                if (j != 0){
                    j = kmp[j - 1];
                    --i;
                }
                else kmp[i] = 0;
            }
        }
    }
};