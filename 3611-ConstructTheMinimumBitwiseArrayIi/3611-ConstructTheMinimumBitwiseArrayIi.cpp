// Last updated: 06/07/2026, 18:52:11
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
        for(const int& n : nums) {
            if(n != 2) result.push_back(n - ((n + 1) & (-n - 1)) / 2);
            else result.push_back(-1);
        }   
        return result;
    }
};