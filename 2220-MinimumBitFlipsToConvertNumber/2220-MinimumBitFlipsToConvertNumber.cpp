// Last updated: 07/09/2026, 22:48:19
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0;
        for (int i = 0; i < 32; i++)
            result += (1 << i & start) != (1 << i & goal);
        
        return result;
    }
};