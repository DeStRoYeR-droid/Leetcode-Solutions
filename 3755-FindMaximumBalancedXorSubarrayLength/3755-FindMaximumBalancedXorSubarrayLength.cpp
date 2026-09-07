// Last updated: 07/09/2026, 22:28:43
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();
        long long balance = 0, xorVal = 0;
        int result = 0;
        unordered_map<long long, int> mp;
        mp[0LL] = -1;

        int i = 0;
        for (const int& val : nums){
            xorVal ^= val;
            balance += (val & 1) ? -1 : 1;
            long long key = (xorVal << 32) + balance;

            if (mp.contains(key)){
                result = max(result, i - mp[key]);
            }
            else {
                mp[key] = i;
            }

            ++i;
        }
        return result;
    }
};