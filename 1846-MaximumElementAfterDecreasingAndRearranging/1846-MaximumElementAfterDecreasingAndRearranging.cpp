// Last updated: 14/09/2026, 09:16:39
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        vector<int> counts = vector(n + 1, 0);
        
        for (int num : arr) {
            counts[min(num, n)]++;
        }
        
        int ans = 1;
        for (int num = 2; num <= n; num++) {
            ans = min(ans + counts[num], num);
        }
        
        return ans;
    }
};