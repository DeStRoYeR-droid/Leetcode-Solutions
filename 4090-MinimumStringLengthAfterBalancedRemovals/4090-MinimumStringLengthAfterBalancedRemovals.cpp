// Last updated: 06/07/2026, 18:48:12
class Solution {
public:
    int minLengthAfterRemovals(string s) {
        const int n = s.size();
        int remove = 0;
        int cA = 0, cB = 0;
        for (const char& ch : s){
            if (ch == 'a') ++cA;
            else ++cB;
            if (cA == cB){
                remove += cA * 2;
                cA = 0;
                cB = 0;
            }
            else if (cA != 0 && cB != 0){
                int mini = min(cA, cB);
                remove += 2 * mini;
                cA -= mini;
                cB -= mini;
            }
        }
        return n - remove;
    }
};