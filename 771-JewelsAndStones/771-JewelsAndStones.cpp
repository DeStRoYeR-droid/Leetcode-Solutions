// Last updated: 14/09/2026, 09:36:15
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelMap(jewels.begin(), jewels.end());
        int result = 0;
        for (const char& ch : stones){
            if (jewelMap.find(ch) != jewelMap.end()) ++result;
        }
        return result;
    }
};