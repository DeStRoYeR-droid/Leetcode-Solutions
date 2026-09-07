// Last updated: 07/09/2026, 22:34:27
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minVal = *min_element(nums.begin(), nums.end());
        if (minVal < k) return -1;

        unordered_set<int> s(nums.begin(), nums.end());
        int size = s.size();

        if (s.find(k) == s.end()) return size;
        else return size - 1;
    }
};