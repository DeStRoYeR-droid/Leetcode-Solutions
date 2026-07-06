// Last updated: 06/07/2026, 18:55:08
class Solution {
private:
    static bool partition(int x, int target){
        if (x == target) return true;
        if (x == 0) return target == 0;
        const int m0 = min(x, 1000);
        for (int m = 10; m <= m0; m *= 10){
            if (partition(x / m, target - x % m)) return 1;
        }
        return 0;
    }

public:
    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i){
            result += (partition(i * i, i)) ? i * i : 0;
        }
        return result;
    }
};