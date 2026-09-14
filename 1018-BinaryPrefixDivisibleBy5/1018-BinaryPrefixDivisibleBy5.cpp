// Last updated: 14/09/2026, 09:30:06
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        const int n = nums.size();
        vector<bool> result(n, false);
        
        int prefix = 0;
        for(int i = 0; i < n; ++i){
            prefix =  (prefix * 2 + nums[i]) % 5;
            if (prefix==0) result[i] = true;
        }

        return result;
    }
};