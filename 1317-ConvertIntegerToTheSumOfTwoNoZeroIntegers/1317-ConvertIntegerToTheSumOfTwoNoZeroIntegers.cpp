// Last updated: 14/09/2026, 09:25:01
class Solution {
public:
    bool hasZeroes(int num){
        if (num == 0) return true;
        while (num > 0){
            if (num % 10 == 0) return true;
            num = num / 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; ++i){
            if (!(hasZeroes(i)) && !(hasZeroes(n - i))) return {i, n - i};
        }
        return {};
    }
};