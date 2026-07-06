// Last updated: 06/07/2026, 18:53:45
class Solution {
public:
    int get_set_bits(int& n){
        int result = 0;
        for (int i = 0; i < 32; i++) result += ((n & 1 << i) != 0);
        return result;
    }
    bool canSortArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> set_bits(n, 0);
        
        for (int i = 0; i < n; i++) { set_bits[i] = get_set_bits(nums[i]);}

        for (int i = 0; i < n - 1; i++){
            for (int j = i+1; j < n; j++){
                if (nums[i] > nums[j]) 
                    if (set_bits[i] != set_bits[j]){
                        return false;
                    }
            }
        }
        return true;
    }
};