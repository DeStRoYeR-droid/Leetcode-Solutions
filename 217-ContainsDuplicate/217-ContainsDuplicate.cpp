// Last updated: 13/07/2026, 22:23:13
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (const int& num : nums){
            if (seen.contains(num)) return true;
            else seen.insert(num);
        }
        return false;
    }
};