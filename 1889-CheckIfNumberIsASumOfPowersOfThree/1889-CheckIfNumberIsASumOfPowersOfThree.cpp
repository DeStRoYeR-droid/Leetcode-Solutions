// Last updated: 06/07/2026, 19:00:55
class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n != 0){
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};