// Last updated: 06/07/2026, 18:51:44
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size(), m = queries.size();
        vector<int> freq(n+1, 0);
        int result = 0, op = 0;
        
        for (int i = 0; i < n; ++i){
            for ( ; op < nums[i] - freq[i]; ++result){
                if (result >= m) return -1;
                const int l = queries[result][0], r = queries[result][1], v = queries[result][2];
                if (r < i) continue;
                freq[max(l, i)] += v;
                freq[r + 1] -= v;
            }
            op += freq[i];
        }

        return result;
    }
};