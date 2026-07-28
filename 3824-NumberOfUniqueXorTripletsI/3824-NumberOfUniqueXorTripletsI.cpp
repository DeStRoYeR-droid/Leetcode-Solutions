// Last updated: 28/07/2026, 23:01:32
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        size_t n = nums.size();
        if (n <= 2) return n;
        return 1 << __lg(n) + 1;
    }
};