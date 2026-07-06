// Last updated: 06/07/2026, 18:50:06
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;

        unordered_map<long long , long long> leftfreq ;
        unordered_map<long long , long long> rightfreq ;
        int ans  =0 ;
        int n = nums.size() ;
        for(int i =1 ; i<n ;i++) rightfreq[nums[i]]++ ;
        leftfreq[nums[0]] ++ ;

        for(int i =1 ; i<n ;i++){
            rightfreq[nums[i]] -- ;

            if(leftfreq.find(nums[i]*2) != leftfreq.end() && rightfreq.find(nums[i]*2) != rightfreq.end()) {
                long long left_cnt = leftfreq[nums[i] *2] ;
                long long right_cnt = rightfreq[nums[i] *2] ;
                ans = (ans + (left_cnt * right_cnt) % MOD) % MOD;
            }
           
           leftfreq[nums[i]] ++ ;
        }
        return ans ;
    }
};