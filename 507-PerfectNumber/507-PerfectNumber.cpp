// Last updated: 13/07/2026, 22:18:44
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num == 1) return false;
        int div_sum = 1;
        for (int i = 2; i * i <= num; ++i){
            if (num % i == 0){
                div_sum += i;
                if (i * i != num) div_sum += num / i;
            }
        }
        return num == div_sum;
    }
};