// Last updated: 05/09/2026, 16:38:08
static const int MOD = 1e9 + 7;
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int result = 0;
        int c1 = 0, c2 = 0;

        for (const int& v : nums){
            if (v < a){
                result = (result + c1 + c2) % MOD;
            }
            else if (v <= b){
                ++c1;
                result = (result + c2) % MOD;
            }
            else{
                ++c2;
            }
        }
        return result;
    }
};