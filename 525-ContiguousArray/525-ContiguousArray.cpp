// Last updated: 02/08/2026, 14:32:08
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefix = 0;
        int result = 0;

        for (int i = 0; i < nums.size(); ++i){
            prefix += (nums[i] == 0) ? -1 : 1;

            if (mp.find(prefix) != mp.end()){
                result = max(result, i - mp[prefix]);
            }
            else mp[prefix] = i;
        }
        return result;
    }
};