// Last updated: 14/09/2026, 09:26:58
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int count[2] = {0, 0};
        for (int i = 0; i < position.size(); i++){
            count[position[i] % 2] += 1;
        }
        return min(count[0], count[1]);
    }
};