// Last updated: 02/08/2026, 14:01:50
class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<pair<int, int>> prefix(n + 2);
        int o = 0, e = 0;
        prefix[0] = {0, 0};
        for (int i = 0; i < n; ++i){
            if (nums[i] % 2) ++o;
            else ++e;
            prefix[i + 1] = {o, e};
        }
        prefix[n + 1] = {o, e};

        int result = 0;
        for (int i = 0; i <= n; ++i){
            for (int j = i; j <= n; ++j){
                int y = prefix[j].first - prefix[i].first;
                int x = prefix[j].second - prefix[i].second;

                if (y > 0 && x * b <= y * a){
                    ++result;
                }
            }
        }
        return result;
    }
};