// Last updated: 14/09/2026, 09:22:21
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