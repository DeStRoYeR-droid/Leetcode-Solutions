// Last updated: 06/07/2026, 18:51:46
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int n = nums.size();
        int cnt = 0;
        int ans = 0;

        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++) {
            cnt++;
            if(i!=n-1 && nums[i]!=nums[i+1]) {
                int l = lower_bound(nums.begin(),nums.end(),nums[i]-k) - nums.begin();
                int r = upper_bound(nums.begin(),nums.end(),nums[i]+k) - nums.begin();
                ans = max(ans,cnt + min(numOperations,(r-l)-cnt));
                cnt = 0;
            }
        }
        
        int l = lower_bound(nums.begin(),nums.end(),nums[n-1]-k) - nums.begin();
        int r = upper_bound(nums.begin(),nums.end(),nums[n-1]+k) - nums.begin();
        ans = max(ans,cnt + min(numOperations,(r-l)-cnt));
        cnt = 0;

        int start = 0, end = 0;
        while(end<n) {
            while(start<end && nums[end]-nums[start]>2*k) {
                start++;
            }
            ans = max(ans,min(numOperations,end-start+1));
            end++;
        }
        return ans;
    }
};