// Last updated: 07/09/2026, 22:35:41
class Solution {
public:
    int minChanges(int n, int k) {
        int result = 0;
        for (int i = 31; i >= 0; --i){
            bool kBit = k & (1 << i);
            bool nBit = n & (1 << i);

            if (kBit && !nBit) return -1;
            else result += (kBit != nBit);
        }
        return result;
    }
};