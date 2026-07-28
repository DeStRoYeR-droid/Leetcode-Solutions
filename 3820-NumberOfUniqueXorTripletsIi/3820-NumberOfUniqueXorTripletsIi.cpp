// Last updated: 28/07/2026, 23:01:35
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        static const int MAX = 2048;

        vector<bool> pairX(MAX, false);
        vector<bool> tripleX(MAX, false);

        int n = nums.size();
        for (int i = 0; i < n; ++i){
            for (int j = i; j < n; ++j){
                pairX[nums[i] ^ nums[j]] = true;
            }
        }

        for (int i = 0; i < MAX; ++i){
            if (!pairX[i]) continue;

            for (int v : nums){
                tripleX[i ^ v] = 1;
            }
        }

        return accumulate(tripleX.begin(), tripleX.end(), 0);
    }
};