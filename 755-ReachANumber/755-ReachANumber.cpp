// Last updated: 13/07/2026, 22:16:40
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