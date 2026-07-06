// Last updated: 06/07/2026, 18:55:32
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int a = 1;
        while (s.count(a)) a <<= 1;
        return a;
    }
};