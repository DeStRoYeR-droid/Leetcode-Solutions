// Last updated: 07/09/2026, 22:45:15
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int toBeSet = __builtin_popcount(num2);
        int alreadySet = __builtin_popcount(num1);

        int result = num1;
        int cur = 0;
        if (alreadySet < toBeSet){
            while (alreadySet < toBeSet){
                if (!(result & (1 << cur))){
                    result = result | (1 << cur);
                    ++alreadySet;
                } 
                ++cur;
            }
        }
        else if (alreadySet > toBeSet){
            while (alreadySet > toBeSet){
                cout << result << endl;
                if (result & (1 << cur)){
                    result = result ^ (1 << cur);
                    --alreadySet;
                }
                ++cur;
            }
        }
        return result;
    }
};