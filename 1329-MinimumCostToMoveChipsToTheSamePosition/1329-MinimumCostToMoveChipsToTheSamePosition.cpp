// Last updated: 06/07/2026, 19:05:00
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