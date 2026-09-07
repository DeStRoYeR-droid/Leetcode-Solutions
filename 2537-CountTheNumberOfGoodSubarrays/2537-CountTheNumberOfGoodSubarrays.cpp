// Last updated: 07/09/2026, 22:43:43
static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    long long countGood(const vector<int>& nums, int k) {
        long long result = 0;
        unordered_map<int, int> mp;

        for (int i = 0, left = 0; i < nums.size(); ++i){
            k -= mp[nums[i]]++;
            while (k <= 0) k += --mp[nums[left++]];
            result += left;
        }
        return result;
    }
};