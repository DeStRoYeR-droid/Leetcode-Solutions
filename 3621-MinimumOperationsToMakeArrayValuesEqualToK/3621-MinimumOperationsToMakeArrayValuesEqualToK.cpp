// Last updated: 06/07/2026, 18:52:00
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