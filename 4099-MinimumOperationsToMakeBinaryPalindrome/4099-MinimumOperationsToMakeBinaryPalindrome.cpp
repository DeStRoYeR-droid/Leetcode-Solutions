// Last updated: 06/07/2026, 18:48:08
class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n, 0);

        for (int i = 0; i < nums.size(); ++i){
            result[i] = solveOne(nums[i]);
        }
        
        return result;
    }

    int solveOne(int n){
        if (isBinPal(n)) return 0;
        long long d = 1;
        while (true){
            if (n - d >= 0 && isBinPal(n - d)) return d;
            if (isBinPal(n + d)) return d;
            ++d;
        }
        return -1;
    }

    bool isBinPal(int x){
        if (x <= 1) return true;

        int reversed = 0, original = x;
        while (x) {
            reversed = (reversed << 1) | (x & 1);
            x >>= 1;
        }
        return original == reversed;
    }
};