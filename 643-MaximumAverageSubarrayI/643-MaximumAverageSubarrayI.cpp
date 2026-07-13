// Last updated: 13/07/2026, 22:17:41
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double total = 0;
        for (int i = 0; i < k; ++i) total += nums[i];
        double maxi = total;
        for (int i = k; i < nums.size(); ++i){
            total -= nums[i - k];
            total += nums[i];
            maxi = max(maxi, total);
        }
        return maxi / k;
    }
};