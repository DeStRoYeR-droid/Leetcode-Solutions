// Last updated: 06/07/2026, 18:52:39
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        const int n = nums.size();
        int countZero = 0, countOne = 0, countAlt = 0, curParity = !(nums[0] & 1);
        for (int i = 0; i < n; ++i){
            int parity = (nums[i] & 1);
            if (parity == 0) countZero++;
            else countOne++;

            if (parity != curParity){
                curParity = parity;
                ++countAlt;
            }
        }
        return max(countZero, max(countOne, countAlt));
    }
};