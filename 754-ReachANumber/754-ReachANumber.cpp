// Last updated: 14/09/2026, 09:37:03
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int cur = 0, i = 1;
        while (cur < target) cur += i++;
        while ((cur - target) & 1) cur += i++;
        return i-1;
    }
};