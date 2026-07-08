// Last updated: 08/07/2026, 18:43:43
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        map<pair<int, int>, int> mp;
        int xr = 0;
        int odd = 0;
        int even = 0;
        int result = 0;

        mp[{0,0}] = -1;

        for (int i = 0; i < n; ++i){
            xr ^= nums[i];

            if (nums[i] % 2 == 0) ++even;
            else ++odd;

            int diff = odd - even;

            pair<int, int> key = {xr, diff};
            if (mp.count(key)){
                result = max(result, i - mp[key]);
            }
            else {
                mp[key] = i;
            }
        }

        return result;
    }
};