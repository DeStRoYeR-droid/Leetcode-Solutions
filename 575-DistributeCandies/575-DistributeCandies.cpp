// Last updated: 13/07/2026, 22:18:17
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> types(candyType.begin(), candyType.end());
        return min(candyType.size() / 2, types.size());
    }
};