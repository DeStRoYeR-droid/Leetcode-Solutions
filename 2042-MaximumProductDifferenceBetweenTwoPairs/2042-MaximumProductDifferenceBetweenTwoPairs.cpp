// Last updated: 06/07/2026, 18:59:59
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        int min1 = 10001;
        int min2 = 10001;

        for (int& num : nums){
            if (max1 < num){
                max2 = max1;
                max1 = num;
            } else if (max2 < num) max2 = num;

            if (min1 > num){
                min2 = min1;
                min1 = num;
            } else if (min2 > num) min2 = num;
        }

        return (max1 * max2) - (min2 * min1);
    }
};