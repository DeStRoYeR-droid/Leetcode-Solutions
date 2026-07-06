// Last updated: 06/07/2026, 18:57:54
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int result = 0;
        for (int i = 0; i < 32; i++)
            result += (1 << i & start) != (1 << i & goal);
        
        return result;
    }
};