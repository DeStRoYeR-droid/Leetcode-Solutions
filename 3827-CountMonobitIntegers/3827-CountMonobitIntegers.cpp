// Last updated: 07/09/2026, 22:23:10
class Solution {
public:
    int countMonobit(int n) {
        int result = 0;
        for (int i = 0; i <= n; ++i){
            int bit = i & 1;
            int copy = i;
            bool isMonobit = true;
            while (copy != 0){
                if ((copy & 1) != bit){
                    isMonobit = false;
                    break;
                }
                copy >>= 1;
            }
            result += isMonobit;
        }
        return result;
    }
};