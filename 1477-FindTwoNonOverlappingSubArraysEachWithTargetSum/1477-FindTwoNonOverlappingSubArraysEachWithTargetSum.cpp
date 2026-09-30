// Last updated: 30/09/2026, 18:28:28
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX / 2); 
        
        int running_total = 0;
        int left = 0;
        int min_so_far = INT_MAX / 2;
        int ans = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            running_total += arr[right];
            
            while (running_total > target) {
                running_total -= arr[left];
                left++;
            }
            
            if (running_total == target) {
                int curr_length = right - left + 1;
                if (left > 0) {
                    ans = min(ans, curr_length + min_len[left - 1]);
                }
                min_so_far = min(min_so_far, curr_length);
            }
            
            min_len[right] = min_so_far;
        }
        
        return ans >= INT_MAX / 2 ? -1 : ans;
    }
};