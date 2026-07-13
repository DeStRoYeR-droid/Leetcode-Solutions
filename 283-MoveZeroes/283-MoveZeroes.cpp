// Last updated: 13/07/2026, 22:21:44
class Solution {
    int zeroPointer(const vector<int>& nums, int start){
        for (int i = start; i < nums.size(); i++){
            if (nums[i] == 0) return i;
        }
        return -1;
    }
public:
    void moveZeroes(vector<int>& nums) {
        int zp = zeroPointer(nums, 0);
        if (zp == -1) return;

        int right = zp + 1;
        while (right < nums.size()){
            if (nums[right] != 0){
                swap(nums[right], nums[zp]);
                zp = zeroPointer(nums, zp);
                if (zp == -1) return;
            }
            right++;
        }
    }
};