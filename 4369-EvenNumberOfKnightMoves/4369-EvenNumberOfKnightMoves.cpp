// Last updated: 20/07/2026, 14:49:34
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int diff = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        return diff % 2 == 0;
    }
};