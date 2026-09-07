// Last updated: 07/09/2026, 22:35:37
class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sumOnes = 0, sumTwos = 0;
        for (const int& val : nums){
            if (val < 10) sumOnes += val;
            else sumTwos += val;
        }
        return sumTwos != sumOnes;
    }
};