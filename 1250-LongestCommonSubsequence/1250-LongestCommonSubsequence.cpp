// Last updated: 06/07/2026, 19:05:27
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int length1 = text1.length();
        const int length2 = text2.length();

        vector<vector<int>>dp(length1 + 1, vector<int>(length2+1));
        
        for (int i = 0; i < length1; i++){
            for (int j = 0; j < length2; j++){
                dp[i+1][j+1] = (text1[i] == text2[j]) ? 1 + dp[i][j] : 
                            max(dp[i][j+1], dp[i+1][j]);
            }
        }

        return dp[length1][length2];
    }
};