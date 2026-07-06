// Last updated: 06/07/2026, 19:03:11
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastOne = -1;
        for (int pos = 0; pos < nums.size(); ++pos){
            if (nums[pos] == 1){
                if (lastOne != -1){
                    if (pos - lastOne - 1 < k) return false;
                }
                lastOne = pos;
            }
        }
        return true;
    }
};