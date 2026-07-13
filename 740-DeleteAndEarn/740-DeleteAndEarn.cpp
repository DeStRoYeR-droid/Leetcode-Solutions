// Last updated: 13/07/2026, 22:16:49
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        static const int n = 10001;
        vector<int> values(n, 0);

        for (const int& num : nums) values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; ++i){
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};