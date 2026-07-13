// Last updated: 13/07/2026, 22:17:00
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        bool result = false;
        while (i < n){
            if (i == bits.size() - 1) result = true;
            if (bits[i]) i += 2;
            else i += 1;
        }
        return result;
    }
};