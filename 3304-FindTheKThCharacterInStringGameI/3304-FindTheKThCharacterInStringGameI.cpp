// Last updated: 07/09/2026, 22:35:07
class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};