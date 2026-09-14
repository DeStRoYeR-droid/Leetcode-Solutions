// Last updated: 14/09/2026, 09:27:49
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, int> mp;

        for (auto it : arr) {
            mp[it] = 1;
        }

        int curr = 1;
        for (auto &it : mp) {
            it.second = curr++;
        }

        for (auto &it : arr) {
            it = mp[it];
        }

        return arr;
    }
};