// Last updated: 06/07/2026, 19:06:07
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        const int length1 = nums1.size();
        const int length2 = nums2.size();

        vector<vector<int>>dp(length1 + 1, vector<int>(length2+1));
        
        for (int i = 0; i < length1; i++){
            for (int j = 0; j < length2; j++){
                dp[i+1][j+1] = (nums1[i] == nums2[j]) ? 1 + dp[i][j] : 
                            max(dp[i][j+1], dp[i+1][j]);
            }
        }

        return dp[length1][length2];
    }
};