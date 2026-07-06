// Last updated: 06/07/2026, 18:52:28
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