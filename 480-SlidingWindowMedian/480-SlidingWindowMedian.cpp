// Last updated: 13/07/2026, 22:19:09
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);

        for (int i = k; i <= nums.size(); ++i) {
            if (k % 2 == 1){
                res.push_back(*mid);
            }
            else{
                res.push_back(((double)*mid + *prev(mid)) / 2.0);
            }
            if (i == nums.size()) break;
            window.insert(nums[i]);

            if (nums[i] < *mid){
                mid--;
            }

            if (nums[i - k] <= *mid){
                mid++;
            }

            window.erase(window.lower_bound(nums[i - k]));
        }

        return res;
    }
};