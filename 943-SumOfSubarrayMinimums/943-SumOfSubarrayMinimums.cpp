// Last updated: 06/07/2026, 19:07:13
class Solution {
    static const int MOD = 1'000'000'007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long result = 0;
        int length = arr.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);

        stack<int> tracker;
        for (int i = 0; i < length; i++){
            while (!tracker.empty() && arr[tracker.top()] >= arr[i]) tracker.pop();
            if (!tracker.empty()) left[i] = tracker.top();
            tracker.push(i);
        }

        tracker = stack<int>();
        for (int i = length - 1; i >= 0; i--){
            while (!tracker.empty() && arr[tracker.top()] > arr[i]) tracker.pop();
            if (!tracker.empty()) right[i] = tracker.top();
            tracker.push(i);
        }

        for (int i = 0; i < length; i++){
            result += static_cast<long long>(i - left[i]) * (right[i] - i) * arr[i];
            result %= MOD;
        }

        return result;
    }
};