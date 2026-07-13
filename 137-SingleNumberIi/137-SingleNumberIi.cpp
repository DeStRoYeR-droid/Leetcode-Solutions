// Last updated: 13/07/2026, 22:26:06
class Solution {
public:
    int singleNumber(const vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (const int& num : nums){
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
            cout << ones << " " << twos << endl;
        }
        return ones;
    }
};