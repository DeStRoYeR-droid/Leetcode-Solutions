// Last updated: 06/07/2026, 19:04:01
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int total_jobs = jobDifficulty.size();
        // Edge case
        if (total_jobs < d) return -1;

        vector<vector<int>> DP_array(total_jobs + 1 , 
                                    vector<int>(d + 1, INT_MAX));
        DP_array[0][0] = 0;
        
        for (int i = 1; i <= total_jobs; i++){
            for (int k = 1; k <= d; k++){
                int max_difficulty = 0;
                for (int j = i; j >= k; j--){
                    max_difficulty = max(max_difficulty , jobDifficulty[j-1]);
                    if (DP_array[j - 1][k - 1] != INT_MAX) {
                        DP_array[i][k] = min(DP_array[i][k], 
                                    DP_array[j - 1][k - 1] + max_difficulty);
                    }
                }
            }
        }

        return (DP_array[total_jobs][d] != INT_MAX)? DP_array[total_jobs][d] : -1;
    }
};