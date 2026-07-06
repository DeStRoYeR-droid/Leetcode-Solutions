// Last updated: 06/07/2026, 18:47:14
typedef long long ll;
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        int mx = 0;
        for (int i = 0; i < n; ++i){
            mx = max(nums[i], mx);
            prefix[i] = gcd(nums[i], mx);
        }

        sort(prefix.begin(), prefix.end());

        ll result = 0;
        int l = 0, r = n - 1;
        while (l < r){
            result += gcd(prefix[l], prefix[r]);
            ++l;
            --r;
        }

        return result;
    }
};