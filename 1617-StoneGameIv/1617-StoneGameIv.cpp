// Last updated: 11/08/2026, 12:50:38
static const int MAX = 1e5 + 1;
static bitset<MAX> dp;

inline static bool init = [](){
    for (int i = 0; i < MAX; ++i){
        if (dp.test(i)) continue;
        for (int j = 1; j * j < MAX - i; ++j){
            dp.set(i + j * j);
        }
    }
    return false;
}();

class Solution {
public:
    bool winnerSquareGame(int n) {
        return dp.test(n);
    }
};