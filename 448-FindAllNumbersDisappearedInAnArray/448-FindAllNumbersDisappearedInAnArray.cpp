// Last updated: 13/07/2026, 22:19:31
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        const int n = nums.size();
        for (int i = 0; i < n; ++i){
            if (nums[i] == i + 1) continue;
            int cur = nums[i], temp;
            int index = i;
            while (cur <= n && nums[cur - 1] != cur){
                int temp = nums[cur - 1];
                nums[cur - 1] = cur;
                cur = temp;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) if (nums[i] != i + 1) result.push_back(i + 1);
        return result;
    }
};