// Last updated: 07/09/2026, 22:42:50
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int a = 1;
        while (s.count(a)) a <<= 1;
        return a;
    }
};