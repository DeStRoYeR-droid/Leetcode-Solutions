// Last updated: 24/08/2026, 22:40:55
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> mod3(3, 0);
        for (const int& val : stones){
            mod3[val % 3]++;
        }

        if (mod3[0] % 2 == 0){
            return mod3[1] > 0 && mod3[2] > 0;
        }
        return abs(mod3[1] - mod3[2]) > 2;
    }
};