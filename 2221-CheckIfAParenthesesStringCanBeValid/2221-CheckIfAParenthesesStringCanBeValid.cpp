// Last updated: 06/07/2026, 18:58:45
class Solution {
public:
    bool canBeValid(string s, string locked) {
        const int length = s.size();
        if (length & 1) return false;

        int minBal = 0, maxBal = 0;
        for (int i = 0; i < length; i++){
            bool open = s[i] == '(';
            bool mask = locked[i] == '0';
            minBal += (!open || mask) ? -1 : 1;
            maxBal += (open || mask) ? 1 : -1;
            if (maxBal < 0) return false;
            minBal = max(minBal, 0);
        }
        return minBal == 0;
    }
};