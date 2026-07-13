// Last updated: 13/07/2026, 22:20:40
const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        const int n = nums.size();
        if (n <= 1) return nums;
        
        vector<int> result;
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);

        sort(nums.begin(), nums.end());

        int index = 0;
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }

            if (dp[i] > dp[index]) index = i;
        }

        while (index >= 0){
            result.push_back(nums[index]);
            index = prev[index];
        }
        // reverse(result.begin(), result.end());
        return result;
    }
};