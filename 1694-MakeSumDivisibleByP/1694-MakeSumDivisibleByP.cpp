// Last updated: 06/07/2026, 19:02:08
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total_sum = 0;
        for (auto &num : nums) total_sum += num;
        
        int total_remainder = total_sum % p;
        if (total_remainder == 0) return 0;

        unordered_map<int, int> prefix_map;
        prefix_map[0] = -1;

        int min_length = nums.size();
        int prefix_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum = (prefix_sum + nums[i]) % p;
            int target = (prefix_sum - total_remainder + p) % p;
            if (prefix_map.find(target) != prefix_map.end()) {
                min_length = min(min_length, i - prefix_map[target]);
            }
            prefix_map[prefix_sum] = i;
        }

        return min_length == nums.size() ? -1 : min_length;
    }
};
