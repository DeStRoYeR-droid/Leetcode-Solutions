// Last updated: 06/07/2026, 18:47:22
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> on(101, false);
        for (const int& val : bulbs) on[val] = !on[val];
        vector<int> result;
        for (int i = 1; i < 101; ++i) if (on[i]) result.push_back(i);
        return result;
    }
};