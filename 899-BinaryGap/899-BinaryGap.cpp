// Last updated: 06/07/2026, 19:07:38
class Solution {
public:
    int binaryGap(int n) {
        int i = 0;
        int result = 0;
        int last = -1;
        while (i < 32){
            if (n & (1 << i)){
                if (last == -1) last = i;
                else{
                    result = max(result, i - last);
                    last = i;
                }
            }
            i++;
        }
        return result;
    }
};