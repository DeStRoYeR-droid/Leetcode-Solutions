// Last updated: 06/07/2026, 18:46:46
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxi = 0;
        vector<vector<int>> mp(10);

        for (const int n : nums){
            string s = to_string(n);
            int diff = *max_element(s.begin(), s.end()) - *min_element(s.begin(), s.end());
            mp[diff].push_back(n);
            maxi = max(maxi, diff);
        }

        return accumulate(mp[maxi].begin(), mp[maxi].end(), 0LL);
    }
};