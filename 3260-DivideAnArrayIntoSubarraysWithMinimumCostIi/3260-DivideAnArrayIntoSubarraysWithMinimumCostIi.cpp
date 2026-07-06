// Last updated: 06/07/2026, 18:53:52
class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int m = k - 1;
        multiset<int> left, right;
        long long current_sum = 0;

        auto balance = [&]() {
            while (left.size() < m && !right.empty()) {
                int val = *right.begin();
                current_sum += val;
                left.insert(val);
                right.erase(right.begin());
            }
            while (left.size() > m) {
                int val = *left.rbegin();
                current_sum -= val;
                right.insert(val);
                left.erase(prev(left.end()));
            }
        };

        for (int i = 1; i <= dist + 1; ++i) {
            right.insert(nums[i]);
        }
        balance();

        long long min_sum = current_sum;

        for (int i = 2; i <= n - dist - 1; ++i) {
            int out_val = nums[i - 1];
            auto it = left.find(out_val);
            if (it != left.end()) {
                current_sum -= out_val;
                left.erase(it);
            } else {
                right.erase(right.find(out_val));
            }

            int in_val = nums[i + dist];
            if (!left.empty() && in_val < *left.rbegin()) {
                current_sum += in_val;
                left.insert(in_val);
            } else {
                right.insert(in_val);
            }

            balance();
            min_sum = min(min_sum, current_sum);
        }

        return (long long)nums[0] + min_sum;
    }
};