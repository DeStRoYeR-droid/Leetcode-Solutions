// Last updated: 07/09/2026, 22:45:29
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n = nums.size();
        vector<int> lastSeen(30, 0), result(n, 1);
        for (int i = n - 1; i >= 0; --i){
            for (int bit = 0; bit < 30; ++bit){
                if ((nums[i] & (1 << bit)) > 0) lastSeen[bit] = i;
                result[i] = max(result[i], lastSeen[bit] - i + 1);
            }
        }
        return result;
    }
};