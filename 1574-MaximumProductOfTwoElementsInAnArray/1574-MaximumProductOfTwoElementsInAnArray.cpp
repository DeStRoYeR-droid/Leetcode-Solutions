// Last updated: 06/07/2026, 19:02:54
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int highest = 0;
        int highest_2 = 0;

        for (int num : nums){
            if (num > highest){
                highest_2 = highest;
                highest = num;
            }

            else if (num > highest_2){
                highest_2 = num;
            }
        }

        return (highest - 1) * (highest_2 -1);
    }
};