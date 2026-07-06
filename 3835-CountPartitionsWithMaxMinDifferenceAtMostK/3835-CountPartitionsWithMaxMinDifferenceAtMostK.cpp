// Last updated: 06/07/2026, 18:50:25
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9+7;
        int n = nums.size();

        vector<long long> dp(n+1,0), pre(n+2,0);
        dp[0] = 1;
        pre[1] = 1;

        deque<int> mn, mx;
        int l=0;
        
        for(int r=0; r<n; r++){
            while(!mx.empty() && mx.back()<nums[r]) mx.pop_back();
            mx.push_back(nums[r]);

            while(!mn.empty() && mn.back()>nums[r]) mn.pop_back();
            mn.push_back(nums[r]);

            while(!mx.empty() && !mn.empty() && mx.front()-mn.front() > k){
                if(mx.front() == nums[l]) mx.pop_front();
                if(mn.front() == nums[l]) mn.pop_front();
                l++;
            }

            dp[r+1] = (pre[r+1] - pre[l] + MOD) % MOD;
            pre[r+2] = (pre[r+1] + dp[r+1]) % MOD;
        }

        return dp[n] % MOD;
    }
};